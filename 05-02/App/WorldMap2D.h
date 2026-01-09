#pragma once
#include <vector>
#include <memory>
#include "Grid.h"

class WorldMap2D final{
public:
	WorldMap2D();
	~WorldMap2D() = default;
	void Init(int screenWidth, int screenHeight, float gridSize);
	void Draw();

	void SetData(int x, int y, int value);
	int GetData(int x, int y);

private:
	std::unique_ptr<Grid> grid_;
	std::vector<std::vector<int>> mapData_;
};