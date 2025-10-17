#pragma once

class Camera
{
	private:
		glm::vec3	cameraPosition;
		glm::vec3	cameraDirection;
		glm::vec3	cameraUp;
		GLfloat		cameraSpeed;
		GLfloat		fov;
		GLfloat		aspect;
		GLfloat		near;
		GLfloat		far;
		GLfloat		wrappingX;
		GLfloat		wrappingY;
		GLfloat		pitch;
		GLfloat		yaw;
		GLfloat		roll;
		GLfloat		sensivity;
		GLfloat		lastX;
		GLfloat		lastY;
		glm::mat4	view;
		glm::mat4	projection;

	public:
		Camera();
		~Camera();
		const glm::vec3&		getCameraPosition() const;
		const glm::vec3&		getCameraDirection() const;
		const glm::vec3&		getCameraUp() const;
		const GLfloat&			getCameraSpeed() const;
		const GLfloat&			getFov() const;
		const GLfloat&			getAspect() const;
		const GLfloat&			getNear() const;
		const GLfloat&			getFar() const;
		const GLfloat&			getWrappingX() const;
		const GLfloat&			getWrappingY() const;
		const GLfloat&			getPitch() const;
		const GLfloat&			getYaw() const;
		const GLfloat&			getRoll() const;
		const GLfloat&			getSensivity() const;
		const GLfloat&			getLastX() const;
		const GLfloat&			getLastY() const;
		const glm::mat4&		getView() const;
		const glm::mat4&		getProjection() const;

		void	setCameraPosition(glm::vec3 cameraPosition);
		void	setCameraDirection(glm::vec3 cameraDirection);
		void	setCameraUp(glm::vec3 cameraUp);
		void	setCameraSpeed(GLfloat cameraSpeed);
		void	setFov(GLfloat fov);
		void	setAspect(GLfloat aspect);
		void	setNear(GLfloat near);
		void	setFar(GLfloat far);
		void	setWrappingX(GLfloat wrapping);
		void	setWrappingY(GLfloat wrapping);
		void	setPitch(GLfloat pitch);
		void	setYaw(GLfloat yaw);
		void	setRoll(GLfloat roll);
		void	setSensivity(GLfloat sensivity);
		void	setLastX(GLfloat lastX);
		void	setLastY(GLfloat lastY);
		void	setView();
		void	setProjectionPerspective();

		void	moveCameraForward();
		void	moveCameraBackward();
		void	moveCameraRight();
		void	moveCameraLeft();

		void	updateCameraVectors();
		void	moveCameraDirection(double xpos, double ypos);

		glm::mat4	createProjectionPerspective(GLfloat fov, GLfloat aspect, GLfloat near, GLfloat far);


};
