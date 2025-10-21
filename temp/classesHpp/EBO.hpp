#pragma once

#include "core/Engine.hpp"

class EBO
{
	public:
		GLuint	ID;

	public:
		EBO();
		~EBO();
		void	init(GLuint *indices, GLsizeiptr size);
		void	bind();
		void	unbind();
		void	deleteBuffer();
};
