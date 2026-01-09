#include "MapSelectionHandler.h"
#include "WorldMap2D.h"
#include "Selector/Selector.h"

MapSelectionHandler::MapSelectionHandler(WorldMap2D& worldMap, Selector& selector) :
	worldMap_(worldMap),
	selector_(selector),
	selectedValue_(0) {
}

void MapSelectionHandler::Update() {
	// セレクターの選択・非選択切り替え処理
	if (selector_.requestSelect_) {
		selector_.isSelected_ = !selector_.isSelected_;
		selector_.requestSelect_ = false;

		if (selector_.isSelected_) {
			// 選択されたときの処理
			selectedValue_ = worldMap_.GetData(selector_.selectX_, selector_.selectY_);
			worldMap_.SetData(selector_.selectX_, selector_.selectY_, 0);
		} else {
			// 非選択されたときの処理
			worldMap_.SetData(selector_.selectX_, selector_.selectY_, selectedValue_);
		}
	}
}
