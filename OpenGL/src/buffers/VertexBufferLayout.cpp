#include "VertexBufferLayout.h"

VertexBufferLayout::VertexBufferLayout(int size, GLenum type, int stride, unsigned int offset) {
	this->size = size;
	this->type = type;
	this->stride = stride;
	this->offset = offset;
}