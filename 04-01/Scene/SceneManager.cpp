#include "SceneManager.h"

#include "TitleScene.h"
#include "InGameScene.h"
#include "ResultScene.h"

SceneManager::SceneManager() {
	currentSceneType = SceneType::Title;
	scenes[SceneType::Title] = std::make_unique<TitleScene>();
	scenes[SceneType::Game] = std::make_unique<InGameScene>();
	scenes[SceneType::Result] = std::make_unique<ResultScene>();
}

void SceneManager::Init() {
	// 最初のシーンの初期化
	if (scenes[currentSceneType]) {
		scenes[currentSceneType]->Init();
	}
}

void SceneManager::Update() {
	// 現在のシーンの更新
	if (scenes[currentSceneType]) {
		scenes[currentSceneType]->Update();

		// シーン切り替えの判定
		if (scenes[currentSceneType]->IsRequestedChangeScene()) {
			currentSceneType = scenes[currentSceneType]->NextScene();
			scenes[currentSceneType]->Init();
		}
	}
}

void SceneManager::Draw() {
	// 現在のシーンの描画
	if (scenes[currentSceneType]) {
		scenes[currentSceneType]->Draw();
	}
}
