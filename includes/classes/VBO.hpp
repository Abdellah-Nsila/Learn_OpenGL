#pragma once

#include "core/Engine.hpp"

class VBO
{
	public:
		GLuint	ID;

	public:
		VBO();
		~VBO();
		void	init(GLfloat *vertices, GLsizeiptr size);
		void	bind();
		void	unbind();
		void	deleteBuffer();
};
