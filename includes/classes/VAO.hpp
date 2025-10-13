#pragma once

#include "includes.hpp"
#include "VBO.hpp"

class VAO
{
	public:
		unsigned int	ID;

	public:
		VAO();
		~VAO();
		void	LinkVBO(VBO VBO, GLuint layout);
		void	bind();
		void	unbind();
		void	deleteBuffer();
};
