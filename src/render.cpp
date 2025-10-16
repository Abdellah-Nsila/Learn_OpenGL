#include "core/Engine.hpp"

int	render(t_game *game)
{
	GLfloat lastTime = glfwGetTime();
	GLfloat currentTime = 0.0f;
	GLfloat deltaTime = 0.0f;
	GLfloat secondCounter = 0.0f;
	GLuint tempFps = 0;
	GLuint fps = 0;

	Shader *ourShader = new Shader("./src/shaders/shader.vert", "./src/shaders/shader.frag");
	t_triangle	t[2];
	setupPipeline(&t[0]);
	t[0].shader = ourShader;

	while (!glfwWindowShouldClose(game->window))
	{
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;

		if (secondCounter <= 1) {
			secondCounter += deltaTime;
			tempFps++;
			// std::cout << "DelataTime: " << deltaTime << std::endl;
		}
		else 
		{
			//"fps" are the actual fps
			fps = tempFps;
			secondCounter = 0;
			tempFps = 0;
			std::cout << "FPS: " << fps << std::endl;
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		drawTriangle(&t[0], 0);
		glfwSwapBuffers(game->window);
		glfwPollEvents();
		lastTime = currentTime;
	}
	destroyPipeline(&t[0]);
	delete ourShader;
	return (EXIT_SUCCESS);
}
