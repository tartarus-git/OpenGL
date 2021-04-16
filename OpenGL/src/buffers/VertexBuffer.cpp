#include "buffers/VertexBuffer.h"

#include <GL/glew.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size, GLenum usage) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

void VertexBuffer::bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

static void unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer() {
	if (id) {
		glDeleteBuffers(1, &id);
	}
}