#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <algorithm>

int main() {
	std::ifstream file("PG3_2025_01_02.txt");
	assert(file.is_open());
	// 格納
	std::vector<std::string> students;
	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string item;
		while (std::getline(ss, item, ',')) {
			students.push_back(item);
		}
	}
	file.close();

	// ソート
	std::sort(students.begin(), students.end());

	// 出力
	for (const std::string& student : students) {
		printf("%s\n", student.c_str());
	}

	return 0;
}