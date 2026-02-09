#include <stdint.h>
#include <iostream>

// 再帰的に賃金を計算する関数
float CalculateWage(float wage, uint32_t hour) {
	if (hour != 0) {
		return wage + CalculateWage(wage * 2.0f - 50.0f, hour - 1);
	} else {
		return 0.0;
	}
}

int main() {
	float wage = 1226.0f;
	uint32_t hour;
	std::cout << "Enter worked hours: ";
	std::cin >> hour;
	// 再帰的に計算した賃金と線形計算の賃金を表示
	std::cout << "Recursion: " << CalculateWage(100.0f, hour) << "$" << std::endl;
	std::cout << "Linear: " << wage * hour << "$" << std::endl;

	// 何時間再帰的に計算した賃金が線形計算の賃金を下回るか
	uint32_t i = 1;
	float recursionWage = CalculateWage(100.0f, i);
	float linearWage = wage;
	while (recursionWage < linearWage)
	{
		i++;
		recursionWage = CalculateWage(100.0f, i);
		linearWage = wage * static_cast<float>(i);
	}
	std::cout << "Greater than liner wage at hour: " << i << std::endl;

	return 0;
}