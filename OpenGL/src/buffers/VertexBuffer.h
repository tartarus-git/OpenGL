#pragma once

#include <GL/glew.h>

class VertexBuffer
{
private:
	unsigned int id = 0;
public:
	VertexBuffer() = default;
	VertexBuffer(const void* data, unsigned int size, GLenum usage);

	void bind() const;
	static void unbind();

	~VertexBuffer();
};