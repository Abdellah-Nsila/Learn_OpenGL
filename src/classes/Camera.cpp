#include "core/Engine.hpp"

Camera::Camera(/* args */)
{
}

Camera::~Camera()
{
}

// ------------------------------------ Getters ------------------------------------
const glm::vec3&	Camera::getCameraPosition() const
{
	return (this->cameraPosition);
}

const glm::vec3&	Camera::getCameraTarget() const
{
	return (this->cameraTarget);
}

const glm::vec3&	Camera::getCameraUp() const
{
	return (this->cameraUp);
}

const GLfloat&	Camera::getCameraSpeed() const
{
	return (this->cameraSpeed);
}

const GLfloat&	Camera::getPitch() const
{
	return (this->pitch);
}

const GLfloat&	Camera::getYaw() const
{
	return (this->yaw);
}

const GLfloat&	Camera::getRoll() const
{
	return (this->roll);
}


// ------------------------------------ Setters ------------------------------------
void	Camera::setView(glm::vec3& cameraPosition, glm::vec3& cameraTarget, glm::vec3& cameraUp)
{
	this->view = glm::lookAt(this->getCameraPosition(), this->getCameraTarget(), this->getCameraUp());
}

void	Camera::setProjection(GLfloat& fovy, GLfloat& aspect, GLfloat& near, GLfloat& far)
{
	this->projection = glm::perspective(fovy, aspect, near, far);
}

void	Camera::setCameraPosition(glm::vec3& cameraPosition)
{
	this->cameraPosition = cameraPosition;
}

void	Camera::setCameraTarget(glm::vec3& cameraTarget)
{
	this->cameraTarget = cameraTarget;
}

void	Camera::setCameraUp(glm::vec3& cameraUp)
{
	this->cameraUp = cameraUp;
}

void	Camera::setCameraSpeed(GLfloat& cameraSpeed)
{
	this->cameraSpeed = cameraSpeed;
}

void	Camera::setPitch(GLfloat& pitch)
{
	this->pitch = pitch;
}

void	Camera::setYaw(GLfloat& yaw)
{
	this->yaw = yaw;
}

void	Camera::setRoll(GLfloat& roll)
{
	this->roll = roll;
}


