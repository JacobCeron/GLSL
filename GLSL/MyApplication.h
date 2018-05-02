#pragma once

#include "RenderEngine/Classes/CoreEngine.h"
#include "RenderEngine/Classes/GameObject.h"

class MyApplication :
	public CoreEngine
{
private:
	GameObject camera;
	GameObject dirLight;
	GameObject dirLight2;
	GameObject mainObj;

public:
	MyApplication(int width, int height, const char* name);
	virtual void Start();
	virtual void Update();
};
