#include <glad\glad.h>

#include <iostream>

#include "RenderMesh.h"

RenderMesh::RenderMesh()
{

}

void RenderMesh::init()
{
	m_vA.init();

	size_t iPosSize{ sizeof(mesh.indexPosition[0]) * mesh.indexPosition.size() };
	size_t iUVSize{ sizeof(mesh.indexUV[0]) * mesh.indexUV.size() };
	size_t iNorSize{ sizeof(mesh.indexNormal[0]) * mesh.indexNormal.size() };

	ElementBuffer m_eB;
	m_eB.init(iPosSize + iUVSize + iNorSize, nullptr);
	m_eB.updateData(0, iPosSize, &mesh.indexPosition[0]);
	m_eB.updateData(iPosSize, iUVSize, &mesh.indexUV[0]);
	m_eB.updateData(iPosSize + iUVSize, iNorSize, &mesh.indexNormal[0]);

	size_t posSize{ sizeof(mesh.position[0]) * mesh.position.size() };
	size_t uvSize{ sizeof(mesh.uv[0]) * mesh.uv.size() };
	size_t norSize{ sizeof(mesh.normal[0]) * mesh.normal.size() };

	VertexBuffer m_vB;
	m_vB.init(posSize + uvSize + norSize, nullptr);
	m_vB.updateData(0, posSize, &mesh.position[0]);
	m_vB.updateData(posSize, uvSize, &mesh.uv[0]);
	m_vB.updateData(posSize + uvSize, norSize, &mesh.normal[0]);

	m_vA.addAttrib(0, 3, VertexArray::FLOAT, false);
	m_vA.addAttrib(1, 2, VertexArray::FLOAT, false);
	m_vA.addAttrib(2, 3, VertexArray::FLOAT, false);

	m_vA.unbind();
}

void RenderMesh::draw()
{
	m_vA.bind();
	if (mesh.indexPosition.size() > 0)
		glDrawElements(GL_TRIANGLES, mesh.indexPosition.size() * mesh.indexPosition[0].size(), GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, mesh.position.size());
	m_vA.unbind();
}