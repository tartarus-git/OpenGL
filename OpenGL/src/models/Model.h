#pragma once

// OpenGL related includes.
#include "buffers/VertexArray.h"
#include "buffers/indexBuffer.h"
#include "textures/Texture.h"

#include <utility>

class Model
{
public:
	VertexArray vertices;
	IndexBuffer indices;

	Texture* textures;
	unsigned int textureCount;

	void setIndices(IndexBuffer&& indices);
	void setVertices(VertexBuffer&& vertices);

	void setTextures(Texture* textures, unsigned int count);
	void bindTextures();
};

