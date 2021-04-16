#include "EntityRenderer.h"

#include "debugging.h"

void EntityRenderer::render(Entity& entity) {
	shader->bind();
	entity.model.vertices.bind();
	entity.model.indices.bind();
	entity.model.bindTextures();
	DEBUG(glDrawElements(GL_TRIANGLES, entity.model.indices.count, GL_UNSIGNED_INT, nullptr));
}