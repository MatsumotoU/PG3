#include "Selector.h"
#include <Novice.h>
#include <algorithm>

#include "SelectorMoveCommand.h"

Selector::Selector(char* key, char* preKey) :
	key_(key),
	preKey_(preKey) {
}

void Selector::Init(int mapWidth, int mapHeight, float size) {
	mapWidth_ = mapWidth;
	mapHeight_ = mapHeight;
	size_ = size;
	selectX_ = 0;
	selectY_ = 0;

	isSelected_ = false;
	requestSelect_ = false;
}

void Selector::Update() {
	// セレクターの選択・非選択切り替え
	if (key_[DIK_SPACE] && !preKey_[DIK_SPACE]) {
		// コマンド履歴のクリア
		while (!commandHistory_.empty()) {
			commandHistory_.pop();
		}

		requestSelect_ = true;
	}

	// セレクターのコマンド登録
	if (isSelected_) {
		if (key_[DIK_UP] && !preKey_[DIK_UP]) {
			commandQueue_.push(std::make_unique<SelectorMoveCommand>(selectX_, selectY_, 0, -1));
		}
		if (key_[DIK_DOWN] && !preKey_[DIK_DOWN]) {
			commandQueue_.push(std::make_unique<SelectorMoveCommand>(selectX_, selectY_, 0, 1));
		}
		if (key_[DIK_LEFT] && !preKey_[DIK_LEFT]) {
			commandQueue_.push(std::make_unique<SelectorMoveCommand>(selectX_, selectY_, -1, 0));
		}
		if (key_[DIK_RIGHT] && !preKey_[DIK_RIGHT]) {
			commandQueue_.push(std::make_unique<SelectorMoveCommand>(selectX_, selectY_, 1, 0));
		}

		if (key_[DIK_Z] && !preKey_[DIK_Z] && Novice::CheckHitKey(DIK_LCONTROL)) {
			if (!commandHistory_.empty()) {
				auto& command = commandHistory_.top();
				command->Undo();
				commandHistory_.pop();
			}
		}
	} else {
		if (key_[DIK_UP] && !preKey_[DIK_UP]) {
			selectY_ = (selectY_ - 1 + mapHeight_) % mapHeight_;
		}
		if (key_[DIK_DOWN] && !preKey_[DIK_DOWN]) {
			selectY_ = (selectY_ + 1) % mapHeight_;
		}
		if (key_[DIK_LEFT] && !preKey_[DIK_LEFT]) {
			selectX_ = (selectX_ - 1 + mapWidth_) % mapWidth_;
		}
		if (key_[DIK_RIGHT] && !preKey_[DIK_RIGHT]) {
			selectX_ = (selectX_ + 1) % mapWidth_;
		}
	}

	// キューの中身を実行
	while (!commandQueue_.empty()) {
		auto& command = commandQueue_.front();
		command->Execute();
		commandHistory_.push(std::move(command));
		commandQueue_.pop();
	}

	// 移動制限
	selectX_ = std::clamp(selectX_, 0, mapWidth_ - 1);
	selectY_ = std::clamp(selectY_, 0, mapHeight_ - 1);
}

void Selector::Draw() {
	Novice::ScreenPrintf(0, 0, "Selector X:%d Y:%d Selected:%s", selectX_, selectY_, isSelected_ ? "True" : "False");
	Novice::ScreenPrintf(0, 20, "Controls: Arrow Keys to Move, Space to Select/Deselect, Ctrl+Z to Undo");
	Novice::ScreenPrintf(0, 40, "Command Queue Size: %d", static_cast<int>(commandQueue_.size()));
	Novice::ScreenPrintf(0, 60, "Command History Size: %d", static_cast<int>(commandHistory_.size()));

	int color = isSelected_ ? RED : BLACK;
	Novice::DrawBox(static_cast<int>(selectX_ * size_),
		static_cast<int>(selectY_ * size_),
		static_cast<int>(size_),
		static_cast<int>(size_),
		0.0f,
		color,
		kFillModeWireFrame);
}
