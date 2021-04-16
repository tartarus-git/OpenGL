#pragma once

#include "rendering/Renderer.h"
#include "entities/Entity.h"

class EntityRenderer : public Renderer
{
public:
	void render(Entity& entity);
};

