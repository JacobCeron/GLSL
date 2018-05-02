#include <glad\glad.h>

#include "MeshRenderer.h"

#include <iostream>

MeshRenderer::MeshRenderer()
{

}

void MeshRenderer::init()
{
	m_vA.init();

	ElementBuffer m_eB;
	if (!mesh.index.empty())
	{
		size_t iPosSize{ sizeof(mesh.index[0]) * mesh.index.size() };
		m_eB.init(iPosSize, &mesh.index[0]);
	}

	VertexBuffer m_vB;

	size_t posSize{ sizeof(mesh.position[0]) * mesh.position.size() };
	size_t uvSize{ sizeof(mesh.uv[0]) * mesh.uv.size() };
	size_t norSize{ sizeof(mesh.normal[0]) * mesh.normal.size() };

	m_vB.init(posSize + uvSize + norSize, nullptr);
	m_vB.updateData(0, posSize, &mesh.position[0]);
	if (!mesh.uv.empty())
		m_vB.updateData(posSize, uvSize, &mesh.uv[0]);
	if (!mesh.normal.empty())
		m_vB.updateData(posSize + uvSize, norSize, &mesh.normal[0]);

	m_vA.addAttrib(0, 3, VertexArray::FLOAT, false, 0, nullptr);
	m_vA.addAttrib(1, 2, VertexArray::FLOAT, false, 0, (void*)(posSize));
	m_vA.addAttrib(2, 3, VertexArray::FLOAT, false, 0, (void*)(posSize + uvSize));

	m_vA.unbind();
}

void MeshRenderer::draw()
{
	m_vA.bind();
	glDrawElements(GL_TRIANGLES, mesh.index.size() * Vector3ui::size, GL_UNSIGNED_INT, 0);
	m_vA.unbind();
}