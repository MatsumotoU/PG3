#include <iostream>
#include <vector>
#include <memory>

class ICommand {
public:
	virtual ~ICommand() = default;
	virtual void Execute() = 0;
};

class RightMoveCommand : public ICommand {
public:
	void Execute() override {
		std::cout << "Move Right" << std::endl;
	}
};
class LeftMoveCommand : public ICommand {
public:
	void Execute() override {
		std::cout << "Move Left" << std::endl;
	}
};
class UpMoveCommand : public ICommand {
public:
	void Execute() override {
		std::cout << "Move Up" << std::endl;
	}
};
class DownMoveCommand : public ICommand {
public:
	void Execute() override {
		std::cout << "Move Down" << std::endl;
	}
};

int main() {
	std::vector<std::unique_ptr<ICommand>> commands;
	commands.push_back(std::make_unique<RightMoveCommand>());
	commands.push_back(std::make_unique<UpMoveCommand>());
	commands.push_back(std::make_unique<LeftMoveCommand>());
	commands.push_back(std::make_unique<DownMoveCommand>());

	for (const auto& command : commands) {
		command->Execute();
	}
	return 0;
}