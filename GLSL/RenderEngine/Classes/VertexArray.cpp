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

void VertexArray::addAttrib(unsigned int index, int size, VertexType type, bool normalize, int stride, const void* offset)
{
	glVertexAttribPointer(index, size, type, normalize, stride, offset);
	glEnableVertexAttribArray(index);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_VAO);
}