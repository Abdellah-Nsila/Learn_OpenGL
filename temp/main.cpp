#include "core/Engine.hpp"

float		transparent = 0.0;

GLfloat		lastX = WIDTH / 2;
GLfloat		lastY = HEIGHT / 2;
GLboolean	firstMouse = GL_TRUE;

t_game	game = {};

int	main()
{
	init_engine();
	glfwDestroyWindow(game.window);
    glfwTerminate();
    return 0;
}
