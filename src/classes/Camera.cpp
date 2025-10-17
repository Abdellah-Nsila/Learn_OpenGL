#include "core/Engine.hpp"

Camera::Camera()
{
	this->cameraPosition = glm::vec3(0.0f, 0.0f,  3.0f);
	this->cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	this->cameraUp = glm::vec3(0.0f, 1.0f,  0.0f);
	this->cameraSpeed = 0.0f;
	this->view = glm::mat4(1.0f);
	this->projection = glm::mat4(1.0f);
	this->pitch = 0.0f;
	this->yaw = 0.0f;
	this->roll = 0.0f;
	this->fov = 0.0f;
}

Camera::~Camera()
{
}

// ------------------------------------ Getters ------------------------------------
const glm::vec3&	Camera::getCameraPosition() const
{
	return (this->cameraPosition);
}

const glm::vec3&	Camera::getCameraFront() const
{
	return (this->cameraFront);
}

const glm::vec3&	Camera::getCameraUp() const
{
	return (this->cameraUp);
}

const GLfloat&	Camera::getCameraSpeed() const
{
	return (this->cameraSpeed);
}

const GLfloat&	Camera::getFov() const
{
	return (this->fov);
}

const GLfloat&	Camera::getAspect() const
{
	return (this->aspect);
}
const GLfloat&	Camera::getNear() const
{
	return (this->near);
}
const GLfloat&	Camera::getFar() const
{
	return (this->far);
}

const GLfloat&	Camera::getWrappingY() const
{
	return (this->wrappingY);
}

const GLfloat&	Camera::getWrappingX() const
{
	return (this->wrappingX);
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

const glm::mat4&	Camera::getView() const
{
	return (this->view);
}

const glm::mat4&	Camera::getProjection() const
{
	return (this->projection);
}

// ------------------------------------ Setters ------------------------------------
void	Camera::setCameraPosition(glm::vec3 cameraPosition)
{
	this->cameraPosition = cameraPosition;
}

void	Camera::setCameraFront(glm::vec3 cameraFront)
{
	this->cameraFront = cameraFront;
}

void	Camera::setCameraUp(glm::vec3 cameraUp)
{
	this->cameraUp = cameraUp;
}

void	Camera::setCameraSpeed(GLfloat cameraSpeed)
{
	this->cameraSpeed = cameraSpeed;
}

void	Camera::setFov(GLfloat fov)
{
	this->fov = fov;
    if (this->fov < 1.0f)
        this->fov = 1.0f;
    if (this->fov > 45.0f)
        this->fov = 45.0f;
}

void	Camera::setAspect(GLfloat aspect)
{
	this->aspect = aspect;
}

void	Camera::setNear(GLfloat near)
{
	this->near = near;
}

void	Camera::setFar(GLfloat far)
{
	this->far = far;
}


void	Camera::setWrappingY(GLfloat wrappingY)
{
	this->wrappingY = wrappingY;
}

void	Camera::setWrappingX(GLfloat wrappingX)
{
	this->wrappingX = wrappingX;
}

void	Camera::setPitch(GLfloat pitch)
{
	this->pitch = pitch;
	if(this->pitch > this->getWrappingY())
		this->pitch = this->getWrappingY();
	if(this->pitch < -this->getWrappingY())
		this->pitch = -this->getWrappingY();
}

void	Camera::setYaw(GLfloat yaw)
{
	this->yaw = yaw;
	//TODOL Optional
	// if(this->yaw > this->getWrappingX())
	// 	this->yaw = this->getWrappingX();
	// if(this->yaw < -this->getWrappingX())
	// 	this->yaw = -this->getWrappingX();
}

void	Camera::setRoll(GLfloat roll)
{
	this->roll = roll;
}

void	Camera::setView()
{
	this->view = glm::lookAt(this->getCameraPosition(), this->getCameraPosition() + this->getCameraFront(), this->getCameraUp());
}

void	Camera::setProjectionPerspective()
{
	this->projection = glm::perspective(this->getFov(), this->getAspect(), this->getNear(), this->getFar());
}

// ------------------------------------ Fancy stuff ------------------------------------
glm::mat4	Camera::createProjectionPerspective(GLfloat fov, GLfloat aspect, GLfloat near, GLfloat far)
{
	return (glm::perspective(fov, aspect, near, far));
}
