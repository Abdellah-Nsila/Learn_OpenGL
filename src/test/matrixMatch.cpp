#include "core/Engine.hpp"

bool matricesEqual(const glm::mat4& a, const glm::mat4& b)
{
	for (int i = 0; i < 4; ++i)
		if (!glm::all(glm::equal(a[i], b[i], 0.0001f)))
			return false;
	return true;
}

// Test Usage inside camera setter view
void	Camera::setView()
{
	auto custom = Camera::createLookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
	auto glm_builtin = glm::lookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);

	if (matricesEqual(custom, glm_builtin))
		std::cout << "Matrices match!" << std::endl;
	else
		std::cout << "Mismatch!" << std::endl;

	// this->view = glm::lookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
	this->view = Camera::createLookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
}
