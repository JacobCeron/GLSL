#pragma once

#include "Mesh.h"
#include "Material.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"

class RenderMesh
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