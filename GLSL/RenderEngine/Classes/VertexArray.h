#pragma once

class VertexArray
{
public:
	enum VertexType
	{
		FLOAT = 0x1406
	};
private:
	unsigned int m_VAO;

public:
	void init();
	void bind();
	void unbind();
	void addAttrib(unsigned int index, int size, VertexType type, bool normalize, int stride, const void* offset);
	~VertexArray();
};