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
	// For Apple machine
	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

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
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	return (EXIT_SUCCESS);
}

int	init_events(t_game *game)
{
	 // Register callbacks BEFORE the main loop
	glfwSetKeyCallback(game->window, key_callback);
	// glfwSetCursorPosCallback(game->window, mouse_callback);

	vertex_input(&game->t[0], vertices, sizeof(vertices));
	Shader *ourShader = new Shader("./src/shaders/shader.vert", "./src/shaders/shader.frag");
	game->t[0].shader = ourShader;

	while (!glfwWindowShouldClose(game->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
	
		// (render stuff)
		draw_triangle(&game->t[0]);

		glfwSwapBuffers(game->window);
		glfwPollEvents();
	}
	clean_shaders(&game->t[0]);
	delete game->t[0].shader;
	return (EXIT_SUCCESS);
}

int	init_engine(t_game *game)
{
	setup_setting(game);
	init_window(game);
	init_events(game);
	return (EXIT_SUCCESS);
}
