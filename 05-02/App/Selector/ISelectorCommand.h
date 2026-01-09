#pragma once
class ISelectorCommand {
public:
	ISelectorCommand() = default;
	virtual ~ISelectorCommand() = default;
	virtual void Execute() = 0;
	virtual void Undo() = 0;
};