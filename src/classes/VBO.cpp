#include "game.hpp"

VBO::VBO()
{
}

VBO::~VBO()
{
}

void	VBO::init(GLfloat *vertices, GLsizeiptr size)
{
	// Generate a buffer has with the unique ID &VBO
	glGenBuffers(1, &ID);
	//! Bind and Copy into VBO
	// Bind the newly created buffer to the GL_ARRAY_BUFFER target
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	// Copy the previously defined vertex data into the buffer's memory
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void	VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void	VBO::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void	VBO::deleteBuffer()
{
	if (ID)
		glDeleteBuffers(1, &ID);
}
