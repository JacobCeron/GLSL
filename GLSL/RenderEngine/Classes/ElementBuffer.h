#pragma once

class ElementBuffer
{
private:
	unsigned int m_EBO;

public:
	void init(size_t size, const void* data);
	void bind();
	void unbind();
	void updateData(size_t offset, size_t size, const void* data);
	~ElementBuffer();
};