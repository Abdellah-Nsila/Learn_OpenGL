#pragma once

#include "core/Engine.hpp"

class Texture
{
	public:
		GLuint	ID;

	public:
		Texture();
		~Texture();
		void	init();
		void	setTextureParameter(GLenum target, GLenum pname, GLint param);
		int		loadTexture(const char *path, GLenum target, GLint level, GLint internalFormat, GLint border, GLenum format, GLenum type);
		void	bind();
		void	unbind();
		void	deleteBuffer();
};
