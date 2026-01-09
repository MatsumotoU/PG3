#pragma once
#include "ISelectorCommand.h"

class SelectorMoveCommand final : public ISelectorCommand {
public:
	SelectorMoveCommand() = delete;
	explicit SelectorMoveCommand(int& selectX, int& selectY, int deltaX, int deltaY);
	~SelectorMoveCommand() override = default;

	void Execute() override;
	void Undo() override;
private:
	int& selectX_;
	int& selectY_;
	int deltaX_;
	int deltaY_;
};