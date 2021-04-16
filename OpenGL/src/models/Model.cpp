#include "Model.h"

void Model::setIndices(IndexBuffer&& indices) { this->indices = indices; }

void Model::setVertices(VertexBuffer&& vertices) {
	this->vertices.setBuffer(std::move(vertices));
}

void Model::setTextures(Texture* textures, unsigned int count) {
	this->textures = textures;
	this->textureCount = count;
}

void Model::bindTextures() {
	for (unsigned int i = 0; i < textureCount; i++) { textures[i].bind(); }
}