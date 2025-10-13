#pragma once

#include "includes.hpp"

class VBO
{
	public:
		unsigned int	ID;

	public:
		VBO();
		VBO(GLfloat *vertices, GLsizeiptr size);
		~VBO();
		void	bind();
		void	unbind();
		void	deleteBuffer();
};
