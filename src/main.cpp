#include "config.h"
#include "Shader.hpp"
#include "Triangle_mesh.hpp"
#include "Material.hpp"
#include "linear_algebros.h"

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
	// Transformation
	// t_vec3	translation = {0.2f, 0.5f, 0.0f};
	// t_mat4	model = createMatrixTransform(translation);
	t_vec3	cameraPos = {-0.4f, 0.0f, 0.2f};
	t_vec3	cameraTarget = {0.0f, 0.0f, 0.0f};
	t_mat4	view = create_look_at(cameraPos, cameraTarget);
	shader->setMat4("view", view);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		t_mat4	model = create_z_rotation(50.0f * glfwGetTime());
		shader->setMat4("model", model);

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
