#include "SelectorMoveCommand.h"

SelectorMoveCommand::SelectorMoveCommand(int& selectX, int& selectY, int deltaX, int deltaY) :
	selectX_(selectX),
	selectY_(selectY),
	deltaX_(deltaX),
	deltaY_(deltaY) {}

void SelectorMoveCommand::Execute() {
	selectX_ += deltaX_;
	selectY_ += deltaY_;
}
void SelectorMoveCommand::Undo() {
	selectX_ -= deltaX_;
	selectY_ -= deltaY_;
}
