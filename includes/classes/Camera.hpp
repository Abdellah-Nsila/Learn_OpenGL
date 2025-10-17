#pragma once

class Camera
{
	private:
		glm::vec3	cameraPosition;
		glm::vec3	cameraFront;
		glm::vec3	cameraUp;
		GLfloat		cameraSpeed;
		glm::mat4	view;
		glm::mat4	projection;
		GLfloat		fov;
		GLfloat		aspect;
		GLfloat		near;
		GLfloat		far;
		GLfloat		wrappingX;
		GLfloat		wrappingY;
		GLfloat		pitch;
		GLfloat		yaw;
		GLfloat		roll;
		//TODO: ADD SENSIVITY

	public:
		Camera();
		~Camera();
		const glm::vec3&		getCameraPosition() const;
		const glm::vec3&		getCameraFront() const;
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
		const glm::mat4&		getView() const;
		const glm::mat4&		getProjection() const;

		void	setCameraPosition(glm::vec3 cameraPosition);
		void	setCameraFront(glm::vec3 cameraFront);
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
		void	setView();
		void	setProjectionPerspective();

		glm::mat4	createProjectionPerspective(GLfloat fov, GLfloat aspect, GLfloat near, GLfloat far);


};
