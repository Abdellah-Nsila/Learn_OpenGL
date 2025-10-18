#include "core/Engine.hpp"

int	render()
{
	GLfloat lastTime = glfwGetTime();
	GLfloat currentTime = 0.0f;
	GLfloat deltaTime = 0.0f;
	GLfloat secondCounter = 0.0f;
	GLuint tempFps = 0;
	GLuint fps = 0;

	// The First default view and projection
	game.camera.setView();
	game.camera.setProjectionPerspective();
	// Setup object to draw
	Shader *ourShader = new Shader("./src/shaders/shader.vert", "./src/shaders/shader.frag");
	t_triangle	t[2];
	setupPipeline(&t[0]);
	t[0].shader = ourShader;

	while (!glfwWindowShouldClose(game.window))
	{
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		game.camera.setCameraSpeed(2.0f * deltaTime);
		key_callback(game.window);

		if (secondCounter <= 1) {
			secondCounter += deltaTime;
			tempFps++;
		}
		else 
		{
			fps = tempFps;
			secondCounter = 0;
			tempFps = 0;
			std::cout << "FPS: " << fps << std::endl;
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		drawTriangle(&t[0], 0);
		glfwSwapBuffers(game.window);
		glfwPollEvents();
		lastTime = currentTime;
	}
	destroyPipeline(&t[0]);
	delete ourShader;
	return (EXIT_SUCCESS);
}
