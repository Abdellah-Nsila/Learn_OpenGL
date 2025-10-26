#include "config.h"
#include "Shader.hpp"
#include "Triangle_mesh.hpp"
#include "Material.hpp"

int	main()
{
	GLFWwindow	*window;

	if (!glfwInit())
	{
		std::cerr << "GLFW couldn't start" << std::endl;
		return (-1);
	}

	window = glfwCreateWindow(1080, 720, "OpenGL_Tuto", NULL, NULL);
	if (!window)
	{
		std::cerr << "GLFW couldn't create a window" << std::endl;
		glfwTerminate();
		return (-1);
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Glad can't load OpenGL" << std::endl;
		glfwDestroyWindow(window);
		glfwTerminate();
		return (-1);
	}

	GLsizei	w,h;
	glfwGetFramebufferSize(window, &w, &h);
	glViewport(0, 0, w, h);
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

	Shader 			*shader = new Shader("shaders/shader.vert", "shaders/shader.frag");
	TriangleMesh	*triangle = new TriangleMesh();
	Material		*material = new Material("textures/dirt.png");
	Material		*mask = new Material("textures/mask.jpg");

	shader->useProgram();
	shader->setInt("material", 0);
	shader->setInt("mask", 1);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);
		shader->useProgram();
		material->use(0);
		mask->use(1);
		triangle->draw();

		glfwSwapBuffers(window);
	}

	shader->deleteProgram();
	delete shader;
	delete triangle;
	delete material;
	delete mask;
	
	glfwDestroyWindow(window);
	glfwTerminate();
	return (0);
}
