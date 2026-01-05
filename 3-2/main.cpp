#include <iostream>

template<typename T>
T Min(T a, T b) {
	return (a < b) ? a : b;
}
template<typename T>
T Max(T a, T b) {
	return (a > b) ? a : b;
}

int main() {
	// int
	std::cout << "Min(3, 5): " << Min(3, 5) << std::endl;
	std::cout << "Max(3, 5): " << Max(3, 5) << std::endl;
	// float
	std::cout << "Min(3.5f, 2.1f): " << Min(3.5f, 2.1f) << std::endl;
	std::cout << "Max(3.5f, 2.1f): " << Max(3.5f, 2.1f) << std::endl;
	// double
	std::cout << "Min(2.718, 3.1415): " << Min(2.718, 3.1415) << std::endl;
	std::cout << "Max(2.718, 3.1415): " << Max(2.718, 3.1415) << std::endl;
	return 0;
}