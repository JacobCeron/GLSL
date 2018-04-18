#pragma once

class VertexArray
{
private:
	unsigned int m_VAO;

public:
	void init();
	void bind();
	void unbind();
	~VertexArray();
};