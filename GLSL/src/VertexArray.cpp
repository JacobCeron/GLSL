#include <glad\glad.h>

#include "VertexArray.h"

void VertexArray::init()
{
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
}

void VertexArray::bind()
{
	glBindVertexArray(m_VAO);
}

void VertexArray::unbind()
{
	glBindVertexArray(0);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_VAO);
}