#include "core/Engine.hpp"

float		transparent = 0.0;
glm::vec3	cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3	cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
GLfloat		cameraSpeed = 0.0f;

GLfloat		lastX = WIDTH / 2;
GLfloat		lastY = HEIGHT / 2;
GLfloat		pitch = 0.0f;
GLfloat		yaw = -90.0f;
GLboolean	firstMouse = GL_TRUE;

int	main()
{
	t_game	game{};

	init_engine(&game);
	glfwDestroyWindow(game.window);
    glfwTerminate();
    return 0;
}
