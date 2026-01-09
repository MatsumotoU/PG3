#pragma once
#include <stack>
#include <queue>
#include <memory>
#include "ISelectorCommand.h"

class Selector final {
public:
	Selector() = delete;
	explicit Selector(char* key,char* preKey);
	~Selector() = default;

	void Init(int mapWidth, int mapHeight,float size);
	void Update();
	void Draw();

	bool isSelected_;
	bool requestSelect_;

	int selectX_;
	int selectY_;

private:
	std::queue<std::unique_ptr<ISelectorCommand>> commandQueue_;
	std::stack<std::unique_ptr<ISelectorCommand>> commandHistory_;

	int mapWidth_;
	int mapHeight_;

	float size_;

	char* key_;
	char* preKey_;
};