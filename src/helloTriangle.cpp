#include "game.hpp"

// Creating memory on the GPU where we store the vertex data
int	vertex_input(t_triangle *t, GLfloat vertices[9], size_t size)
{
	//! Genrate
	// Generate a VAO
	glGenVertexArrays(1, &t->VAO);
	// Generate a buffer has with the unique ID &VBO
	glGenBuffers(1, &t->VBO);

	//! Bind VAO Vertex Array Object
	glBindVertexArray(t->VAO);

	//! Bind and Copy into VBO
	// Bind the newly created buffer to the GL_ARRAY_BUFFER target
	glBindBuffer(GL_ARRAY_BUFFER, t->VBO);
	// Copy the previously defined vertex data into the buffer's memory
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

	// Tell OpenGL how it should interpret the vertex data (per vertex attribute)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	// Enable the vertex attribute with glEnableVertexAttribArray giving the vertex attribute location as its argument
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	//! Unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return (EXIT_SUCCESS);
}

void	clean_shaders(t_triangle *t)
{
	glDeleteVertexArrays(1, &t->VAO);
    glDeleteBuffers(1, &t->VBO);
    glDeleteBuffers(1, &t->EBO);
    t->shader->deleteProgram();
}

int	draw_triangle(t_triangle *t)
{
	// Every shader and rendering call after glUseProgram will now use this program object
	t->shader->useProgram();
	// Update
	// t->shader->setFloat("xOffset", 0.3f);
	// Bind VAO
	glBindVertexArray(t->VAO);
	// Draws primitives using the currently active shader, the previously defined vertex attribute configuration
	// and with the VBO's vertex data (indirectly bound via the VAO)
	glDrawArrays(GL_TRIANGLES, 0, 3);
	return (EXIT_SUCCESS);
}
