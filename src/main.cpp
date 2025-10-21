#include "iostream"
// #include <Learn_OpenGL/extern/glfw/glfw.hpp>
#include "../extern/glfw/glfw.hpp"

int	main()
{
	// std::cout << "Hello World" << std::endl;
	GLFWwindow	*window = nullptr;
	GLfloat		width = 1080.0f;
	GLfloat		height = 720.0f;
	const char		*title = "Engine";


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
	window = glfwCreateWindow(static_cast<GLuint>(width), static_cast<GLuint>(height), title, nullptr, nullptr);
	if (!window) {
		std::cerr << "Failed to create GLFW window\n";
		glfwTerminate();
		return (EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);


	// Initialize GLAD: this must happen *after* creating the OpenGL context
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD\n";
		return (EXIT_FAILURE);
	}
	glViewport(0, 0, width, height);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);


	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Render
		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
    glfwTerminate();
	return (EXIT_SUCCESS);

}