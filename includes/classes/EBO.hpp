#pragma once

#include "includes.hpp"

class EBO
{
	public:
		GLuint	ID;

	public:
		EBO();
		~EBO();
		void	init(GLfloat *indices, GLsizeiptr size);
		void	bind();
		void	unbind();
		void	deleteBuffer();
};
