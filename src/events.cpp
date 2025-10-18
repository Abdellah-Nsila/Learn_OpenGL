#include "core/Engine.hpp"

void	key_callback(GLFWwindow* window)
{
	// Polygone Mode
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	// Tranparent textures
	else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		transparent > 1.0 ? transparent = 0.0 : transparent += 0.05;
	}
	else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		transparent < 0.0 ? transparent = 1.0 : transparent -= 0.05;
	}
	// Mouve Arround
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		game.camera.moveCameraForward();
		game.camera.setView();
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		game.camera.moveCameraBackward();
		game.camera.setView();
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		game.camera.moveCameraRight();
		game.camera.setView();
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		game.camera.moveCameraLeft();
		game.camera.setView();
	}
	// Exit
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void	mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (!window)
		return ;
	std::cout << "Mouse moved to: " << xpos << ", " << ypos << std::endl;
	if (firstMouse)
	{
		game.camera.setLastX(xpos);
		game.camera.setLastY(ypos);
		firstMouse = GL_FALSE;
	}
	game.camera.moveCameraDirection(xpos, ypos);
	game.camera.setView();
}

void	scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	std::cout << "ScroolY: " << yoffset << std::endl;
	(void)window;
	(void)xoffset;
	game.camera.setFov(game.camera.getFov() - (GLfloat)yoffset);
	game.camera.setProjectionPerspective();
}
