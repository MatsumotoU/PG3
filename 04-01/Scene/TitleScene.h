#pragma once
#include "IScene.h"
class TitleScene final : public IScene
{
public:
	TitleScene() = default;
	~TitleScene() override = default;
	void Init() override;
	void Update() override;
	void Draw() override;

	SceneType NextScene() override;
	bool IsRequestedChangeScene() override;

private:
	bool changeScene = false;
};