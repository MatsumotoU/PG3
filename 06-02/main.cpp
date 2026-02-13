#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <atomic>

void LoadCSV(const std::string& filename, std::vector<std::vector<std::string>>& data, std::atomic<bool>& finished) {
	std::ifstream file(filename);
	std::string line;
	while (std::getline(file, line)) {
		std::vector<std::string> row;
		size_t pos = 0, prev = 0;
		while ((pos = line.find(',', prev)) != std::string::npos) {
			row.push_back(line.substr(prev, pos - prev));
			prev = pos + 1;
		}
		row.push_back(line.substr(prev));
		data.push_back(row);
	}
	finished = true;
}

int main() {
	std::vector<std::vector<std::string>> csvData;
	std::atomic<bool> finished(false);

	std::thread loader(LoadCSV, "sample.csv", std::ref(csvData), std::ref(finished));

	// バックグラウンドでCSV読み込み中
	while (!finished) {
		std::cout << "CSV読み込み中...\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	loader.join();

	// 読み込んだデータを表示
	std::cout << "CSV読み込み完了。行数: " << csvData.size() << std::endl;
	for (const auto& row : csvData) {
		for (const auto& cell : row) {
			std::cout << cell << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}