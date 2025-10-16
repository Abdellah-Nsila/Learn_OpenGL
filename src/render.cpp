#include "core/Engine.hpp"

int	render(t_game *game)
{
	Shader *ourShader = new Shader("./src/shaders/shader.vert", "./src/shaders/shader.frag");
	t_triangle	t[2];
	setupPipeline(&t[0]);
	t[0].shader = ourShader;

	while (!glfwWindowShouldClose(game->window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		drawTriangle(&t[0], 0);
		glfwSwapBuffers(game->window);
		glfwPollEvents();
	}
	destroyPipeline(&t[0]);
	delete ourShader;
	return (EXIT_SUCCESS);
}
