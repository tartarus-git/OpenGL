#include "BasicShader.h"

#include <GL/glew.h>

#include "debugging.h"

BasicShader::BasicShader() {
	loadVertexShader("res/shaders/basic/vertex.glsl");
	loadFragmentShader("res/shaders/basic/fragment.glsl");
	finalize();

	// Texture.
	DEBUG(u_Texture = glGetUniformLocation(id, "u_Texture"));
	bind();
	DEBUG(glUniform1i(u_Texture, 0));

	// Color.
	DEBUG(u_Color = glGetUniformLocation(id, "u_Color"));									// This can technically return -1 if it can't find the uniform in the code, so be careful.
}

void BasicShader::loadColor(float r, float g, float b, float a) {
	bind();
	DEBUG(glUniform4f(u_Color, r, g, b, a));
}