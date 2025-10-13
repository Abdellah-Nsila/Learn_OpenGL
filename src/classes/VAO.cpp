#include "game.hpp"

VAO::VAO()
{
}

VAO::~VAO()
{
}

void	VAO::init()
{
	// Generate a VAO
	glGenVertexArrays(1, &ID);
}

void	VAO::LinkAttrib(VBO VBO, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid *pointer)
{
	VBO.bind();
	// Tell OpenGL how it should interpret the vertex data (per vertex attribute)
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	// Enable the vertex attribute with glEnableVertexAttribArray giving the vertex attribute location as its argument
	glEnableVertexAttribArray(index);
	VBO.unbind();
}

void	VAO::bind()
{
	glBindVertexArray(ID);
}

void	VAO::unbind()
{
	glBindVertexArray(0);
}

void	VAO::deleteBuffer()
{
	if (ID)
		glDeleteVertexArrays(1, &ID);
}
