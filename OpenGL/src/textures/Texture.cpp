#include "Texture.h"

#include <GL/glew.h>

#include <stb_image.h>

#include "debugging.h"

Texture::Texture(const char* file, GLenum slot) {
	// Set slot.
	this->slot = slot;

	// Load texture from file.
	stbi_set_flip_vertically_on_load(true);										// TODO: Does this need to be called every time?
	data = stbi_load(file, &width, &height, &bpp, 4);

	// Create texture.
	DEBUG(glGenTextures(1, &id));
	DEBUG(glActiveTexture(slot));
	DEBUG(glBindTexture(GL_TEXTURE_2D, id));

	// Set necessary parameters. You have to set these.
	DEBUG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	DEBUG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	DEBUG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	DEBUG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	DEBUG(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));			// First GL_RGBA needs the 8 at the end, the second one can't have it. Also, you don't necessarily have to pass in data here. You can save that for later.

	stbi_image_free(data);					// Free intermediate buffer because you don't need it anymore.
}

void Texture::bind() const {
	DEBUG(glActiveTexture(slot));
	DEBUG(glBindTexture(GL_TEXTURE_2D, id));
}

void Texture::unbind() {
	DEBUG(glActiveTexture(slot));
	DEBUG(glBindTexture(GL_TEXTURE_2D, 0));
}

Texture::~Texture() {
	if (id) {
		DEBUG(glDeleteTextures(1, &id));
	}
}