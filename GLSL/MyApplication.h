#pragma once

#include "RenderEngine/Classes/Application.h"
#include "RenderEngine/Classes/RenderMesh.h"

class MyApplication :
	public Application
{
private:
	RenderMesh sphere;

public:
	virtual void Start();
	virtual void Update();
};
