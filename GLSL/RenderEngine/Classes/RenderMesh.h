#pragma once

#include "Component.h"

#include "Mesh.h"
#include "Material.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"

class RenderMesh
	: public Component
{
public:
	Mesh mesh;
	Material material;
private:
	VertexArray m_vA;

public:
	RenderMesh();
	void init();
	void draw();
};