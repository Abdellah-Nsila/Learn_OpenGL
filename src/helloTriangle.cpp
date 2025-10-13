#include "game.hpp"

GLfloat vertices[] = {
	// positions         // colors
	0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
};

GLfloat vertices1[] = {
	-0.8f,  0.8f, 0.0f,  // top right
	-0.8f, -0.2f, 0.0f,  // bottom right
	-0.2f, -0.2f, 0.0f,  // bottom left
};

GLfloat vertices2[] = {
	0.8f,  0.8f, 0.0f,  // top right
	0.8f, -0.8f, 0.0f,  // bottom right
	-0.8f, -0.8f, 0.0f,  // bottom left
};

int	setupPipeline(t_triangle *t)
{
	t->vao.init();
	t->vao.bind();
	t->vbo.init(vertices, sizeof(vertices));
	t->vao.LinkAttrib(t->vbo, 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
	t->vao.LinkAttrib(t->vbo, 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	t->vao.unbind();
	t->vbo.unbind();
	return EXIT_SUCCESS;
}

void	destroyPipeline(t_triangle *t)
{
	t->vao.deleteBuffer();
	t->vbo.deleteBuffer();
	t->shader->deleteProgram();
}

int	drawTriangle(t_triangle *t)
{
	t->shader->useProgram();
	t->vao.bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	return (EXIT_SUCCESS);
}
