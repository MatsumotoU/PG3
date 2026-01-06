#pragma once
#include "IScene.h"
class ResultScene final : public IScene
{
public:
	ResultScene() = default;
	~ResultScene() override = default;
	void Init() override;
	void Update() override;
	void Draw() override;

	SceneType NextScene() override;
	bool IsRequestedChangeScene() override;

private:
	bool changeScene = false;
};