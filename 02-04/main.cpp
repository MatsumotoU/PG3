#include <stdint.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <locale.h>
#include <functional>

void ShowResult(int roll, int userGuess) {
	wprintf(L"正解は%dでした\n", roll);
	if (roll % 2 == userGuess) {
		wprintf(L"おめでとう！当たりです。\n");
	} else {
		wprintf(L"残念！はずれです。\n");
	}
}

void DelayReaval(uint32_t delayMs, int roll, int userGuess) {
	wprintf(L"サイコロを振っています...\n");
	Sleep(delayMs);
	std::function fn = ShowResult;
	fn(roll, userGuess);
}

int main() {
	SetConsoleOutputCP(65001); // UTF-8
	setlocale(LC_ALL, "");

	wprintf(L"サイコロを振ります。偶数なら0、奇数なら1を入力してください: ");
	int playerIn = 0;
	scanf_s("%d", &playerIn);
	srand(static_cast<unsigned int>(time(0)));
	int random_value = rand() % 6 + 1;
	std::function fn = DelayReaval;
	fn(1000, random_value, playerIn);

	return 0;
}