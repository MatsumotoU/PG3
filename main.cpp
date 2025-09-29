#include <iostream>
#include <Windows.h>

int main() {
	SetConsoleOutputCP(65001);
	char str[] = "こんにちは、世界。";
	printf("%s\n", str);
	return 0;
}