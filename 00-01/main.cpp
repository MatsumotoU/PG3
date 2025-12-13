#include <stdint.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <locale.h>
#include <functional>
#include <map>

class Enemy {
public:
	Enemy() {
		funcMap["Move"] = &Enemy::Move;
		funcMap["Shot"] = &Enemy::Shot;
		funcMap["Release"] = &Enemy::Release;
	}

	void Move() {
		std::cout << "Enemy is moving!" << std::endl;
	}
	void Shot() {
		std::cout << "Enemy is attacking!" << std::endl;
	}
	void Release() {
		std::cout << "Enemy is releasing!" << std::endl;
	}

	void ExecuteAction(const std::string& action) {
		auto it = funcMap.find(action);
		if (it != funcMap.end()) {
			(this->*(it->second))();
		} else {
			std::cout << "Action not found!" << std::endl;
		}
	}

private:
	std::map<std::string, void (Enemy::*)()> funcMap;
};

int main() {
	Enemy enemy;
	enemy.ExecuteAction("Move");
	enemy.ExecuteAction("Shot");
	enemy.ExecuteAction("Release");
	return 0;
}