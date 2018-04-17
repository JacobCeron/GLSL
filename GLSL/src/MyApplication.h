#pragma once

#include "Application.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"

class MyApplication :
	public Application
{
private:
	Shader shaderCube;
	Shader shaderLight;

	VertexBuffer vB;
	ElementBuffer eB;
	unsigned int VAO;

public:
	virtual void Start();
	virtual void Update();
};
