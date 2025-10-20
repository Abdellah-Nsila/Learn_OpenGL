#include "core/Engine.hpp"

Camera::Camera() : worldUp(glm::vec3(0.0f, 1.0f, 0.0f))
{
	this->cameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	this->cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	this->cameraRight = glm::normalize(glm::cross(this->cameraFront, this->worldUp));
	this->cameraUp = glm::normalize(glm::cross(this->cameraRight, this->cameraFront));
	this->cameraSpeed = 0.0f;
	this->view = glm::mat4(1.0f);
	this->projection = glm::mat4(1.0f);
	this->fov = 0.0f;
	this->pitch = 0.0f;
	this->yaw = 0.0f;
	this->roll = 0.0f;
	this->sensivity = 0.1f;
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

const glm::vec3&	Camera::getCameraRight() const
{
	return (this->cameraRight);
}

const glm::vec3&	Camera::getWorldUp() const
{
	return (this->worldUp);
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

const GLfloat&	Camera::getSensivity() const
{
	return (this->sensivity);
}

const GLfloat&	Camera::getLastX() const
{
	return (this->lastX);
}

const GLfloat&	Camera::getLastY() const
{
	return (this->lastY);
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

void	Camera::setCameraRight()
{
	this->cameraRight = glm::normalize(glm::cross(this->cameraFront, this->worldUp));
}

void	Camera::setCameraUp()
{
	this->cameraUp = glm::normalize(glm::cross(this->cameraRight, this->cameraFront));
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
	if(this->pitch > this->wrappingY)
		this->pitch = this->wrappingY;
	if(this->pitch < -this->wrappingY)
		this->pitch = -this->wrappingY;
}

void	Camera::setYaw(GLfloat yaw)
{
	this->yaw = yaw;
	//TODO: Optional
	// if(this->yaw > this->wrappingX)
	// 	this->yaw = this->wrappingX;
	// if(this->yaw < -this->wrappingX)
	// 	this->yaw = -this->wrappingX;
}

void	Camera::setRoll(GLfloat roll)
{
	this->roll = roll;
}

void	Camera::setSensivity(GLfloat sensivity)
{
	this->sensivity = sensivity;
}

void	Camera::setLastX(GLfloat lastX)
{
	this->lastX = lastX;
}

void	Camera::setLastY(GLfloat lastY)
{
	this->lastY = lastY;
}

void	Camera::setView()
{
	this->view = glm::lookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
	// this->view = Camera::createLookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
}

void	Camera::setProjectionPerspective()
{
	this->projection = glm::perspective(glm::radians(this->fov), this->aspect, this->near, this->far);
}

// ------------------------------------ Move ------------------------------------
void	Camera::moveCameraForward()
{
	this->setCameraPosition(this->cameraPosition + this->cameraFront * this->cameraSpeed);
}

void	Camera::moveCameraBackward()
{
	this->setCameraPosition(this->cameraPosition - this->cameraFront * this->cameraSpeed);
}

void	Camera::moveCameraRight()
{
	this->setCameraPosition(this->cameraPosition + this->cameraRight * this->cameraSpeed);
	// this->setCameraPosition(this->cameraPosition + glm::normalize(glm::cross(this->cameraFront, this->cameraUp)) * this->cameraSpeed);
}

void	Camera::moveCameraLeft()
{
	this->setCameraPosition(this->cameraPosition - this->cameraRight * this->cameraSpeed);
}

// ------------------------------------ Mouse ------------------------------------
//TODO: Decide if you want to use getters and setters inside the class or not ?
void	Camera::updateCameras()
{
	GLfloat	pitchRadians = glm::radians(this->pitch);
	GLfloat	yawRadians = glm::radians(this->yaw);

	glm::vec3	front;
	front.x = cos(yawRadians) * cos(pitchRadians);
	front.y = sin(pitchRadians);
	front.z = sin(yawRadians) * cos(pitchRadians);
	this->setCameraFront(glm::normalize(front));

	//TODO: Also re-calculate the CameraRight and Up vector (insted of recalculate each move key event)
	this->setCameraRight();
	this->setCameraUp();
}

void	Camera::moveCameraFront(double xpos, double ypos)
{
	GLfloat	xoffset = xpos - this->lastX;
	GLfloat	yoffset = this->lastY - ypos; // reversed since y-coordinates range from bottom to top
	this->setLastX(xpos);
	this->setLastY(ypos);

	xoffset *= this->sensivity;
	yoffset *= this->sensivity;

	this->setYaw(glm::mod(this->yaw + xoffset, 360.0f));
	this->setPitch(this->pitch + yoffset);

	this->updateCameras();
}

// ------------------------------------ Fancy stuff ------------------------------------
glm::mat4	Camera::createLookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up)
{
	// Create View (x,y,z) axis from
	glm::vec3	z_axis = glm::normalize(position - target);
	glm::vec3	x_axis = glm::normalize(glm::cross(glm::normalize(up), z_axis));
	glm::vec3	y_axis = glm::cross(z_axis, x_axis);

	// Translate matrix pased on new position
	glm::mat4	translation = glm::mat4(1.0f);
	translation[3][0] = -position.x;
	translation[3][1] = -position.y;
	translation[3][2] = -position.z;

	// Rotation matrix based on nee (x,y,z) axis
	glm::mat4	rotation = glm::mat4(1.0f);
	// -----------------------------
	rotation[0][0] = x_axis.x;
	rotation[1][0] = x_axis.y;
	rotation[2][0] = x_axis.z;
	// -----------------------------
	rotation[0][1] = y_axis.x;
	rotation[1][1] = y_axis.y;
	rotation[2][1] = y_axis.z;
	// -----------------------------
	rotation[0][2] = z_axis.x;
	rotation[1][2] = z_axis.y;
	rotation[2][2] = z_axis.z;

	// Final view matrix (using Product PxT translate then rotation)
	return (rotation * translation);
}

glm::mat4	Camera::createView(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 cameraUp)
{
	return (glm::lookAt(cameraPosition, cameraTarget, cameraUp));
}

glm::mat4	Camera::createPerspectiveProjection(GLfloat fov, GLfloat aspect, GLfloat near, GLfloat far)
{
	return (glm::perspective(fov, aspect, near, far));
}

// glm::mat4	Camera::createProjectionOrtho(GLfloat fov, GLfloat aspect, GLfloat near, GLfloat far)
// {	
// 	float aspectRatio = (float)WIDTH / HEIGHT;
// 	float orthoWidth = HEIGHT * aspectRatio;
// 	float orthoHeight = HEIGHT;
// 	float zoomFactor = .009;
// 	this->projection = glm::ortho(-orthoWidth * zoomFactor, orthoWidth * zoomFactor, -orthoHeight * zoomFactor, orthoHeight * zoomFactor, 0.0f, 100.0f);
// }
