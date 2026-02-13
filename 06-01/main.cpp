#include <iostream>
#include <vector>
#include <thread>
#include <functional>

void PrintMessage(const std::string& message) {
	std::cout << message << std::endl;
}

int main() {
	std::vector<std::thread> threads;
	threads.push_back(std::thread(PrintMessage, "thread 1"));
	threads.back().join(); // メインスレッドがthread 1の終了を待機
	threads.push_back(std::thread(PrintMessage, "thread 2"));
	threads.back().join(); // メインスレッドがthread 2の終了を待機
	threads.push_back(std::thread(PrintMessage, "thread 3"));
	threads.back().join(); // メインスレッドがthread 3の終了を待機
	return 0;
}