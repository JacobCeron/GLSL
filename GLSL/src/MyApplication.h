#pragma once

#include "Application.h"

#include "RenderMesh.h"

class MyApplication :
	public Application
{
private:
	RenderMesh object;

public:
	virtual void Start();
	virtual void Update();
};
