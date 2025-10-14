#include "typedef.hpp"

EBO::EBO()
{
}

EBO::~EBO()
{
}

void	EBO::init(GLfloat *indices, GLsizeiptr size)
{
	// Generate a EBO
	glGenBuffers(1, &ID);
	//! Bind and Copy into EBO
	// Bind Element Buffer Object
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	// Copy the indices into the buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW); 
}

void	EBO::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void	EBO::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void	EBO::deleteBuffer()
{
	if (ID)
		glDeleteBuffers(1, &ID);
}
