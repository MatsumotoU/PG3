#include "WorldMap2D.h"
#include <Novice.h>

WorldMap2D::WorldMap2D() {
	grid_ = std::make_unique<Grid>();
}

void WorldMap2D::Init(int screenWidth, int screenHeight, float gridSize) {
	// グリッドの初期化
	grid_->Init(static_cast<float>(screenWidth), static_cast<float>(screenHeight), gridSize);

	// マップデータの初期化
	for (int i = 0; i < screenHeight / gridSize; ++i) {
		std::vector<int> row;
		for (int j = 0; j < screenWidth / gridSize; ++j) {
			row.push_back(0); // 初期値として0を設定
		}
		mapData_.push_back(row);
	}

	// ランダムに5つのマスを1に設定
	for (int n = 0; n < 5; ++n) {
		int randRow = rand() % mapData_.size();
		int randCol = rand() % mapData_[0].size();
		mapData_[randRow][randCol] = 1;
	};
}

void WorldMap2D::Draw() {
	grid_->Draw();

	// マップデータの描画
	for (int i = 0; i < mapData_.size(); ++i) {
		for (int j = 0; j < mapData_[i].size(); ++j) {
			if (mapData_[i][j] != 0) {
				Novice::DrawBox(static_cast<int>(j * grid_->GetGridSize()),
					static_cast<int>(i * grid_->GetGridSize()),
					static_cast<int>(grid_->GetGridSize()),
					static_cast<int>(grid_->GetGridSize()),
					0.0f,
					WHITE,
					kFillModeSolid);
			}
		}
	}
}

void WorldMap2D::SetData(int x, int y, int value) {
	if (y >= 0 && y < mapData_.size() && x >= 0 && x < mapData_[y].size()) {
		mapData_[y][x] = value;
	}
}

int WorldMap2D::GetData(int x, int y) {
	if (y >= 0 && y < mapData_.size() && x >= 0 && x < mapData_[y].size()) {
		return mapData_[y][x];
	}
	return -1; // 範囲外の場合は-1を返す
}