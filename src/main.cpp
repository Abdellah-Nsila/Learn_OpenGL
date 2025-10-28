#include "config.h"
#include "Shader.hpp"
#include "Triangle_mesh.hpp"
#include "Material.hpp"

int	glfwSetFramebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
	return (0);
};

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
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

	Shader 			*shader = new Shader("shaders/shader.vert", "shaders/shader.frag");
	TriangleMesh	*triangle = new TriangleMesh();
	Material		*material = new Material("textures/dirt.png");
	Material		*mask = new Material("textures/mask.jpg");

	shader->useProgram();
	shader->setInt("material", 0);
	shader->setInt("mask", 1);

	glm::vec3	cameraPos = {-5.0f, 0.0f, 3.0f};
	glm::vec3	cameraTarget = {0.0f, 0.0f, 0.0f};
	glm::vec3	up = {0.0f, 1.0f, 0.0f};
	glm::mat4	view = glm::lookAt(cameraPos, cameraTarget, up);
	shader->setMat4("view", glm::value_ptr(view));

	glm::mat4	projection = glm::perspective(glm::radians(45.0f), 1080.0f / 720.0f, 0.1f, 10.0f);
	shader->setMat4("projection", glm::value_ptr(projection));

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glm::mat4	model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-0.2f, 0.4f, 0.0f));
		model = glm::rotate(model, static_cast<GLfloat>(glfwGetTime()), glm::vec3(0.0f, 0.0f, 1.0f));
		shader->setMat4("model", glm::value_ptr(model));

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
