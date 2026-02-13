#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

void PrintMessage(const std::string& message, int my_order, int& current_order, std::mutex& mtx, std::condition_variable& cv) {
	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock, [&] { return my_order == current_order; });
	std::cout << message << std::endl;
	++current_order;
	cv.notify_all();
}

int main() {
	std::vector<std::thread> threads;
	std::mutex mtx;
	std::condition_variable cv;
	int current_order = 0;

	threads.push_back(std::thread(PrintMessage, std::string("thread 1"), 0, std::ref(current_order), std::ref(mtx), std::ref(cv)));
	threads.push_back(std::thread(PrintMessage, std::string("thread 2"), 1, std::ref(current_order), std::ref(mtx), std::ref(cv)));
	threads.push_back(std::thread(PrintMessage, std::string("thread 3"), 2, std::ref(current_order), std::ref(mtx), std::ref(cv)));

	for (auto& t : threads) {
		t.join();
	}
	return 0;
}