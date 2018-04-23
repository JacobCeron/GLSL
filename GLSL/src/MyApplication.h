#pragma once

#include "Application.h"

#include "RenderMesh.h"

class MyApplication :
	public Application
{
private:
	RenderMesh cube;
	RenderMesh sphere;
	RenderMesh torus;
	RenderMesh heart;

public:
	virtual void Start();
	virtual void Update();
};
