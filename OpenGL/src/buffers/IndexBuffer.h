#pragma once

#include <GL/glew.h>

class IndexBuffer
{
private:
	unsigned int id = 0;
public:
	unsigned int count;

	IndexBuffer() = default;
	IndexBuffer(const unsigned int* data, unsigned int size, GLenum usage);

	void bind() const;
	static void unbind();

	~IndexBuffer();
};