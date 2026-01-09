#include "Grid.h"
#include <Novice.h>

void Grid::Init(float screenWidth, float screenHeight, float gridSize) {
	width_ = screenWidth;
	height_ = screenHeight;
	size_ = gridSize;
}

void Grid::Draw() {
	for (float x = 0; x <= width_; x += size_) {
		Novice::DrawLine(static_cast<int>(x), 0, static_cast<int>(x), static_cast<int>(height_), WHITE);
	}
	for (float y = 0; y <= height_; y += size_) {
		Novice::DrawLine(0, static_cast<int>(y), static_cast<int>(width_), static_cast<int>(y), WHITE);
	}
}

const float& Grid::GetGridSize() const {
	return size_;
}
