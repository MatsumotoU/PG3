#pragma once
#include <memory>
#include <map>
#include "IScene.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager() = default;

	void Init();
	void Update();
	void Draw();

private:
	SceneType currentSceneType;
	std::map<SceneType, std::unique_ptr<IScene>> scenes;
};