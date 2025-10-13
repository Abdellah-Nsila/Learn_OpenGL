#include "game.hpp"

VAO::VAO()
{
	// Generate a VAO
	glGenVertexArrays(1, &ID);
}

VAO::~VAO()
{
}

void	VAO::LinkVBO(VBO VBO, GLuint layout)
{
	(void)layout;
	VBO.bind();
	// Tell OpenGL how it should interpret the vertex data (per vertex attribute)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	// Enable the vertex attribute with glEnableVertexAttribArray giving the vertex attribute location as its argument
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
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
	glDeleteVertexArrays(1, &ID);
}
