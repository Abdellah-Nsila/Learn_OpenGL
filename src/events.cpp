#include "game.hpp"

void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (action == GLFW_PRESS)
		std::cout << "Key pressed: " << key << std::endl;
	else if (action == GLFW_RELEASE)
		std::cout << "Key released: " << key << std::endl;

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void	mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (!window)
		return ;
	std::cout << "Mouse moved to: " << xpos << ", " << ypos << std::endl;
}
