#pragma once

#include "buffers/VertexBuffer.h"
#include "buffers/VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int id;

	VertexBuffer buffer;
public:
	VertexArray();

	void setBuffer(VertexBuffer&& buffer);
	void bind();
	void put(unsigned int index, VertexBufferLayout layout);
	void enable(unsigned int index);

	~VertexArray();
};