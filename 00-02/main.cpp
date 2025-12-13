#include <iostream>
#include <Windows.h>
#include <list>

int main() {
	std::list<const char*> stations;
	printf("1970:\n\n");
	stations.push_back("Tokyo");
	stations.push_back("Kanda");
	stations.push_back("Akihabara");
	stations.push_back("Okachimachi");
	stations.push_back("Ueno");
	stations.push_back("Uguisudani");
	stations.push_back("Nippori");
	stations.push_back("Tabata");
	stations.push_back("Komagome");
	stations.push_back("Sugamo");
	stations.push_back("Otsuka");
	stations.push_back("Ikebukuro");
	stations.push_back("Mejiro");
	stations.push_back("Takadanobaba");
	stations.push_back("Shin-Okubo");
	stations.push_back("Shinjuku");
	stations.push_back("Yoyogi");
	stations.push_back("Harajuku");
	stations.push_back("Shibuya");
	stations.push_back("Ebisu");
	stations.push_back("Meguro");
	stations.push_back("Gotanda");
	stations.push_back("Osaki");
	stations.push_back("Shinagawa");
	stations.push_back("Tamachi");
	stations.push_back("Hamamatsucho");
	stations.push_back("Shimbashi");
	stations.push_back("Yurakucho");

	for (const char* station : stations) {
		std::cout << station << std::endl;
	}

	printf("\n2019:\n\n");
	auto it = stations.begin();
	std::advance(it, 7);
	stations.insert(it, "Nishi-Nippori");
	for (const char* station : stations) {
		std::cout << station << std::endl;
	}

	printf("\n2022:\n\n");
	it = stations.begin();
	std::advance(it, 25);
	stations.insert(it, "Takanawa Gateway");
	for (const char* station : stations) {
		std::cout << station << std::endl;
	}

	return 0;
}