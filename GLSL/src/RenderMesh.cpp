#include <glad\glad.h>

#include <iostream>

#include "RenderMesh.h"

RenderMesh::RenderMesh()
{

}

void RenderMesh::init()
{
	m_vA.init();

	ElementBuffer m_eB;
	if (!mesh.indexPosition.empty())
	{
		size_t iPosSize{ sizeof(mesh.indexPosition[0]) * mesh.indexPosition.size() };

		m_eB.init(iPosSize, &mesh.indexPosition[0]);
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

void RenderMesh::draw()
{
	m_vA.bind();
	if (!mesh.indexPosition.empty())
		glDrawElements(GL_TRIANGLE_STRIP, mesh.indexPosition.size() * mesh.indexPosition[0].size(), GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, mesh.position.size());
	m_vA.unbind();
}