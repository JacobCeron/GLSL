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

void VertexArray::addAttrib(unsigned int index, int size, VertexType type, bool normalize)
{
	glVertexAttribPointer(index, size, type, normalize, 0, nullptr);
	glEnableVertexAttribArray(index);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_VAO);
}