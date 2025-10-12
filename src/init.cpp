#include "game.hpp"

int setup_setting(t_game *game)
{
	game->width = WIDTH;
	game->height = HEIGHT;
	game->window = nullptr;
	game->title = TITLE; // assuming TITLE is a const char* or std::string
	return (EXIT_SUCCESS);
}

int	init_window(t_game *game)
{
	if (!glfwInit()) {
		std::cerr << "Failed to init GLFW\n";
		return (EXIT_FAILURE);
	}
	// request an OpenGL 3.3 core profile context, e.g.:
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// (if you want compatibility, you can skip the core profile hint)
	game->window = glfwCreateWindow(game->width, game->height, game->title.c_str(), NULL, NULL);
	if (!game->window) {
		std::cerr << "Failed to create GLFW window\n";
		glfwTerminate();
		return (EXIT_FAILURE);
	}
	glfwMakeContextCurrent(game->window);

	// Initialize GLAD: this must happen *after* creating the OpenGL context
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD\n";
		return (EXIT_FAILURE);
	}

	glViewport(0, 0, game->width, game->height);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	return (EXIT_SUCCESS);
}

int	init_events(t_game *game)
{
	 // Register callbacks BEFORE the main loop
	glfwSetKeyCallback(game->window, key_callback);
	// glfwSetCursorPosCallback(game->window, mouse_callback);

	vertex_input();
	vertex_shader();
	fragment_shader();
	while (!glfwWindowShouldClose(game->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
	
		// (render stuff)
		use_program();

		glfwSwapBuffers(game->window);
		glfwPollEvents();
	}
	//TODO: Add a triangle struct
	glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
	return (EXIT_SUCCESS);
}

int	init_engine(t_game *game)
{
	setup_setting(game);
	init_window(game);
	init_events(game);
	return (EXIT_SUCCESS);
}
