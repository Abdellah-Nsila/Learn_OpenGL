#pragma once

#include "includes.hpp"
#include "VBO.hpp"

class VAO
{
	public:
		GLuint	ID;

	public:
		VAO();
		~VAO();
		void	init();
		void	LinkAttrib(VBO VBO, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid *pointer);
		void	bind();
		void	unbind();
		void	deleteBuffer();
};
