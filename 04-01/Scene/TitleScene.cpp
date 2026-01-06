#include "TitleScene.h"

void TitleScene::Init() {
}

void TitleScene::Update() {
}

void TitleScene::Draw() {
}

SceneType TitleScene::NextScene() {
	return SceneType::Game;
}

bool TitleScene::IsRequestedChangeScene() {
	return changeScene;
}
