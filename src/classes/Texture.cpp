#include "typedef.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "../includes/utils/stb_image.h"

Texture::Texture()
{
}

Texture::~Texture()
{
}

void	Texture::init()
{
	// Generate a Texture
	glGenTextures(1, &ID);
}

void	Texture::setTextureParameter(GLenum target, GLenum pname, GLint param)
{
	glTexParameteri(target, pname, param);
}

int	Texture::loadTexture(const char *path, GLenum target, GLint level, GLint internalFormat, GLint border, GLenum format, GLenum type)
{
	int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
	unsigned char *pixels = stbi_load(path, &width, &height, &nrChannels, 0);

	if (pixels)
	{
		glTexImage2D(target, level, internalFormat, width, height, border, format, type, pixels);
		glGenerateMipmap(target);
	}
	else
	{
		std::cerr << "Failed to load texture: " << path << std::endl;
		return (EXIT_FAILURE);
	}
	stbi_image_free(pixels);
	return (EXIT_SUCCESS);
}

void	Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, ID);
}

void	Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void	Texture::deleteBuffer()
{
	if (ID)
		glDeleteTextures(1, &ID);
}
