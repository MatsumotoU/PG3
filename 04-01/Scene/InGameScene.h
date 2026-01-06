#pragma once
#include "IScene.h"
class InGameScene final : public IScene
{
public:
	InGameScene() = default;
	~InGameScene() override = default;
	void Init() override;
	void Update() override;
	void Draw() override;

	SceneType NextScene() override;
	bool IsRequestedChangeScene() override;

private:
	SceneType nextScene = SceneType::Result;
	bool changeScene = false;
};