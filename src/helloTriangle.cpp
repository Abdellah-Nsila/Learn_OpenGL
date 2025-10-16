#include "core/Engine.hpp"

// GLfloat	vertices[] = {
//     // positions          // colors           // texture coords
//      0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
//      0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
//     -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//     -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
// };

// GLuint	indices[] = {
// 	0, 1, 3, // first triangle
//     1, 2, 3  // second triangle
// };

GLfloat vertices[] = {
    // positions          // colors             // tex coords
    -0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,    0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,    1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 1.0f,    1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 1.0f,    1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.0f,    0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 1.0f,    0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,   1.0f, 0.0f, 0.0f,    0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 0.0f,    1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 1.0f,    1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 1.0f,    1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 0.0f,    0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,   1.0f, 0.0f, 1.0f,    0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,   1.0f, 0.0f, 0.0f,    1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f,    1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,    0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,    0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,   1.0f, 1.0f, 0.0f,    0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,   1.0f, 0.0f, 1.0f,    1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,   1.0f, 0.0f, 0.0f,    1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f,    1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,    0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,    0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,   1.0f, 1.0f, 0.0f,    0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,   1.0f, 0.0f, 1.0f,    1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,    0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,    1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,   0.0f, 0.0f, 1.0f,    1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,   0.0f, 0.0f, 1.0f,    1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,   1.0f, 1.0f, 0.0f,    0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 1.0f,    0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 0.0f,    0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f,    1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 1.0f,    1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,   0.0f, 0.0f, 1.0f,    1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 0.0f,    0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 1.0f,    0.0f, 1.0f
};

int	setupTexture(Texture *t, const char *path, GLint param, GLenum format)
{
	t->init();
	t->bind();
	t->setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, param);
	t->setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, param);
	t->setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	t->setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	t->loadTexture(path, GL_TEXTURE_2D, 0, GL_RGB, 0, format, GL_UNSIGNED_BYTE);
	return (EXIT_SUCCESS);
}

int	setupPipeline(t_triangle *t)
{
	t->vao.init();
	t->vao.bind();
	t->vbo.init(vertices, sizeof(vertices));
	// t->ebo.init(indices, sizeof(indices));
	// t->ebo.bind();
	t->vao.LinkAttrib(t->vbo, 0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
	t->vao.LinkAttrib(t->vbo, 1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	t->vao.LinkAttrib(t->vbo, 2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));

	setupTexture(&(t->texture[0]), "./textures/container.png", GL_CLAMP_TO_EDGE, GL_RGB);
	setupTexture(&(t->texture[1]), "./textures/awesomeface.png", GL_CLAMP_TO_EDGE, GL_RGBA);
	
	t->vao.unbind();
	t->vbo.unbind();
	return EXIT_SUCCESS;
}

void	destroyPipeline(t_triangle *t)
{
	t->vao.deleteBuffer();
	t->vbo.deleteBuffer();
	// t->ebo.deleteBuffer();
	t->shader->deleteProgram();
	t->texture[0].deleteBuffer();
	t->texture[1].deleteBuffer();
}

int	drawTriangle(t_triangle *t, int idx)
{
	(void)idx;
	glActiveTexture(GL_TEXTURE0);
	t->texture[0].bind();
	glActiveTexture(GL_TEXTURE1);
	t->texture[1].bind();

	t->shader->useProgram();
	t->shader->setInt("Texture1", 0);
	t->shader->setInt("Texture2", 1);
	t->shader->setFloat("Transparent", transparent);
	
	glm::mat4	model = glm::mat4(1.0f);
	model = glm::rotate(model, static_cast<GLfloat>(glfwGetTime()), glm::vec3(0.5f, 1.0f, 0.0f));

	glm::mat4	view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	glm::mat4	projection;
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	// t->shader->setMat4("model", glm::value_ptr(model));
	t->shader->setMat4("model", model);
	t->shader->setMat4("view", view);
	t->shader->setMat4("projection", projection);

	t->vao.bind();
	// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	return (EXIT_SUCCESS);
}
