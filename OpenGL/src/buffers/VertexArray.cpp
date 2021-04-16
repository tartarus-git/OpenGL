#include "VertexArray.h"

// OpenGL related includes.
#include <GL/glew.h>

// Other includes.
#include "buffers/VertexBufferLayout.h"

VertexArray::VertexArray() {
	glGenVertexArrays(1, &id);
}

void VertexArray::setBuffer(VertexBuffer&& buffer) {
	this->buffer = buffer;
}

void VertexArray::bind() {
	glBindVertexArray(id);
}

void VertexArray::put(unsigned int index, VertexBufferLayout layout) {
	bind();
	buffer.bind();
	glVertexAttribPointer(index, layout.size, layout.type, GL_FALSE, layout.stride, (const void*)layout.offset);
}

void VertexArray::enable(unsigned int index) {
	bind();
	glBindVertexArray(id);
	glEnableVertexAttribArray(index);
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &id);
}