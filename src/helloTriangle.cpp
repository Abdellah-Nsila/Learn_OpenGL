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

glm::vec3 cubePositions[] = {
    glm::vec3( 0.0f,  0.0f,  -6.0f), 
    glm::vec3( 2.0f,  5.0f, -18.0f), 
    glm::vec3(-1.5f, -2.2f, -2.5f),  
    glm::vec3(-3.8f, -2.0f, -14.3f),  
    glm::vec3( 2.4f, -0.4f, -6.5f),  
    glm::vec3(-1.7f,  3.0f, -9.5f),  
    glm::vec3( 1.3f, -2.0f, -5.5f),  
    glm::vec3( 1.5f,  2.0f, -5.5f), 
    glm::vec3( 1.5f,  0.2f, -3.5f), 
    glm::vec3(-1.3f,  1.0f, -3.5f)  
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

	setupTexture(&(t->texture[0]), "./textures/dirt.png", GL_CLAMP_TO_EDGE, GL_RGB);
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

	game.camera.setView();



	t->shader->setMat4("view", game.camera.getView());
	t->shader->setMat4("projection", game.camera.getProjection());

	t->vao.bind();
	// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	for (int i = 0; i < 10; i++)
	{
		glm::mat4	model = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[i]);
		model = glm::rotate(model, static_cast<GLfloat>(glfwGetTime()), glm::vec3(1.0f, 0.3f, 0.5f));
		t->shader->setMat4("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	return (EXIT_SUCCESS);
}
