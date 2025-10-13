#pragma once

#include "includes.hpp"

class EBO
{
	public:
		unsigned int	ID;

	public:
		EBO();
		EBO(GLfloat *indices, GLsizeiptr size);
		~EBO();
		void	bind();
		void	unbind();
		void	deleteBuffer();
};
