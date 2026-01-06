#include "ResultScene.h"

void ResultScene::Init() {
}

void ResultScene::Update() {
}

void ResultScene::Draw() {
}

SceneType ResultScene::NextScene() {
	return SceneType::Title;
}

bool ResultScene::IsRequestedChangeScene() {
	return changeScene;
}
