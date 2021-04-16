#pragma once

#include <GL/glew.h>

class Texture
{
private:
	unsigned int id = 0;
	GLenum slot;
	unsigned char* data;
	int width, height;
	int bpp;

public:
	Texture() = default;
	Texture(const char* file, GLenum slot = GL_TEXTURE0);

	void bind() const;
	void unbind();

	~Texture();
};

