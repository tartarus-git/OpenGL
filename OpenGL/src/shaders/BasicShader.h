#pragma once

#include "shaders/ShaderProgram.h"

class BasicShader : public ShaderProgram
{
private:
	int u_Texture;

	int u_Color;
public:
	BasicShader();

	void loadColor(float r, float g, float b, float a);
};

