#pragma once

#include "shaders/ShaderProgram.h"

class Renderer
{
public:
	ShaderProgram* shader;

	void clear();
};