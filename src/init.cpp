#include "core/Engine.hpp"

int	setup_camera()
{
	game.camera = Camera();
	game.camera.setCameraPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	game.camera.setCameraFront(glm::vec3(0.0f, 0.0f, -1.0f));
	game.camera.setCameraRight();
	game.camera.setCameraUp();
	game.camera.setFov(45.0f);
	game.camera.setWrappingX(89.0f);
	game.camera.setWrappingY(89.0f);
	game.camera.setYaw(-90.0f);
	game.camera.setAspect(WIDTH / HEIGHT);
	game.camera.setNear(0.1f);
	game.camera.setFar(100.0f);
	game.camera.setLastX(game.width / 2.0);
	game.camera.setLastY(game.height / 2.0);
	return (EXIT_SUCCESS);
}

int setup_setting()
{
	game.width = WIDTH;
	game.height = HEIGHT;
	game.window = nullptr;
	game.title = TITLE;
	// Camera
	setup_camera();
	return (EXIT_SUCCESS);
}

int	init_window()
{
	if (!glfwInit()) {
		std::cerr << "Failed to init GLFW\n";
		return (EXIT_FAILURE);
	}
	// request an OpenGL 3.3 core profile context, e.g.:
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	// For Apple machine
	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

	// (if you want compatibility, you can skip the core profile hint)
	game.window = glfwCreateWindow(static_cast<GLuint>(game.width), static_cast<GLuint>(game.height), game.title.c_str(), NULL, NULL);
	if (!game.window) {
		std::cerr << "Failed to create GLFW window\n";
		glfwTerminate();
		return (EXIT_FAILURE);
	}
	glfwMakeContextCurrent(game.window);
	// glfwSwapInterval(GL_FALSE); // 0 = disable VSync, 1 = enable
	glfwSetInputMode(game.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	// Initialize GLAD: this must happen *after* creating the OpenGL context
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD\n";
		return (EXIT_FAILURE);
	}
	glViewport(0, 0, game.width, game.height);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glEnable(GL_DEPTH_TEST);  
	return (EXIT_SUCCESS);
}

int	init_events()
{
	// Prevent first-frame jump when GLFW warps the mouse
	glfwSetCursorPos(game.window, game.width / 2.0, game.height / 2.0);
	firstMouse = GL_TRUE; // reset the flag here
	glfwSetCursorPosCallback(game.window, mouse_callback);
	glfwSetScrollCallback(game.window, scroll_callback); 
	render();
	return (EXIT_SUCCESS);
}

int	init_engine()
{
	setup_setting();
	init_window();
	init_events();
	return (EXIT_SUCCESS);
}
