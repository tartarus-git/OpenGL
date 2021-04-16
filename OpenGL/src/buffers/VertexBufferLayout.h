#pragma once

#include <GL/glew.h>

class VertexBufferLayout
{
public:
	int size;
	GLenum type;
	int stride;
	int offset;

	VertexBufferLayout(int size, GLenum type, int stride, unsigned int offset);
};