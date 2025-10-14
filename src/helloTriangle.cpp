#include "typedef.hpp"

GLfloat vertices[] = {
	// positions         // colors			// texture coords
	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,	0.0f, 0.0f,   // bottom left
	0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,	1.0f, 0.0f,   // bottom right
	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,	0.5f, 1.0f    // top 
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
	t->vao.LinkAttrib(t->vbo, 0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
	t->vao.LinkAttrib(t->vbo, 1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	t->vao.LinkAttrib(t->vbo, 2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
	
	
	t->texture.init();
	t->texture.bind();
	t->texture.setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	t->texture.setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	t->texture.setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	t->texture.setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	t->texture.loadTexture("./textures/container.png", GL_TEXTURE_2D, 0, GL_RGB, 0, GL_RGB, GL_UNSIGNED_BYTE);
	
	t->vao.unbind();
	t->vbo.unbind();
	return EXIT_SUCCESS;
}

void	destroyPipeline(t_triangle *t)
{
	t->vao.deleteBuffer();
	t->vbo.deleteBuffer();
	t->shader->deleteProgram();
	t->texture.deleteBuffer();
}

int	drawTriangle(t_triangle *t)
{
	t->shader->useProgram();
	t->texture.bind();
	t->vao.bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	return (EXIT_SUCCESS);
}
