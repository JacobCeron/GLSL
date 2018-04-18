#pragma once

#include "Application.h"
#include "Shader.h"
#include "Material.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"

class MyApplication :
	public Application
{
private:
	Material cubeMat;
	Material lightMat;

	VertexArray vA;
	VertexBuffer vB;
	ElementBuffer eB;

public:
	virtual void Start();
	virtual void Update();
};
