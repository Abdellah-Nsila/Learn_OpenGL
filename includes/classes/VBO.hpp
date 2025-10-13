#pragma once

#include "includes.hpp"

class VBO
{
	public:
		unsigned int	ID;

	public:
		VBO();
		~VBO();
		void	init(GLfloat *vertices, GLsizeiptr size);
		void	bind();
		void	unbind();
		void	deleteBuffer();
};
