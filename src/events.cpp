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
		cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
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
		lastX = xpos;
		lastY = ypos;
		firstMouse = GL_FALSE;
	}

	GLfloat	xoffset = xpos - lastX;
	GLfloat	yoffset = lastY - ypos; // reversed since y-coordinates range from bottom to top
	lastX = xpos;
	lastY = ypos;

	xoffset *= SENSIVITY;
	yoffset *= SENSIVITY;

	pitch += yoffset;
	if(pitch > 89.0f)
		pitch =  89.0f;
	if(pitch < -89.0f)
		pitch = -89.0f;

	yaw += xoffset;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);
}

void	scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	(void)window;
	(void)xoffset;
    FOV -= (float)yoffset;
    if (FOV < 1.0f)
        FOV = 1.0f;
    if (FOV > 45.0f)
        FOV = 45.0f; 
}
