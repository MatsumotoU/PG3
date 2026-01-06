#pragma once
#include "SceneType.h"

class IScene
{
public:
	virtual ~IScene() = default;
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual SceneType NextScene() = 0;
	virtual bool IsRequestedChangeScene() = 0;
};