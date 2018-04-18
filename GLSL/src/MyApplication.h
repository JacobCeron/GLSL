#pragma once

#include "Application.h"
#include "Shader.h"
#include "Material.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"

class MyApplication :
	public Application
{
private:
	Material cubeMat;
	Material lightMat;

	VertexBuffer vB;
	ElementBuffer eB;
	unsigned int VAO;

public:
	virtual void Start();
	virtual void Update();
};
