#include "core/Engine.hpp"

int	render(t_game *game)
{
	Shader *ourShader = new Shader("./src/shaders/shader.vert", "./src/shaders/shader.frag");
	t_triangle	t;
	setupPipeline(&t);
	t.shader = ourShader;

	while (!glfwWindowShouldClose(game->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		drawTriangle(&t);
		glfwSwapBuffers(game->window);
		glfwPollEvents();
	}
	destroyPipeline(&t);
	delete t.shader;
	return (EXIT_SUCCESS);
}
