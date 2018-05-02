#pragma once

#include "Component.h"

#include "Mesh.h"
#include "Material.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"

class MeshRenderer
	: public Component
{
public:
	Mesh mesh;
	Material material;
private:
	VertexArray m_vA;

public:
	MeshRenderer();
//	void init(); // Inside Renderer Engine
//	void draw(); // Inside Renderer Engine

private:
	void init();
	void draw();

	friend class RendererEngine;
};