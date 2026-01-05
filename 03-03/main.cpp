#include <iostream>
#include <memory>
#include <vector>

class IEnemy {
public:
	virtual ~IEnemy() {};
	virtual void attack() = 0;
};

class Goblin : public IEnemy {
public:
	void attack() override {
		std::cout << "Goblin attacks with a club!" << std::endl;
	}
};
class Troll : public IEnemy {
public:
	void attack() override {
		std::cout << "Troll attacks with a huge hammer!" << std::endl;
	}
};

int main() {
	std::vector<std::unique_ptr<IEnemy>> enemies;
	enemies.resize(2);
	enemies[0] = std::make_unique<Goblin>();
	enemies[1] = std::make_unique<Troll>();

	for (const auto& enemy : enemies) {
		enemy->attack();
	}
	return 0;
}