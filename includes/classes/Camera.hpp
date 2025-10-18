#pragma once

class Camera
{
	private:
		// Camera X (Right vector)
		glm::vec3	cameraPosition;
		// Camera Z (Front vector)
		glm::vec3	cameraDirection;
		// Camera Y (Up vector)
		glm::vec3	cameraUp;
		// Factor speed (deltatime recommended)
		GLfloat		cameraSpeed;
		// Field of view in Y-axis
		GLfloat		fov;
		// Aspct Ratio WIDTH / HEIGH
		GLfloat		aspect;
		// The closest boundary of the viewable frustum
		GLfloat		near;
		// The furthest boundary of the viewable frustum
		GLfloat		far;
		// Max angle in X-axis
		GLfloat		wrappingX;
		// Max angle in Y-axis
		GLfloat		wrappingY;
		// The up-and-down movement
		GLfloat		pitch;
		// The left-and-right movement
		GLfloat		yaw;
		// The side-to-side wing-tilting movement
		GLfloat		roll;
		// Sensivity of mouse movement
		GLfloat		sensivity;
		// Last traked mouse X-position
		GLfloat		lastX;
		// Last traked mouse Y-position
		GLfloat		lastY;
		// View matrix sets up the "camera" by transforming world coordinates into a view coordinate system, placing the camera at the origin and looking down the positive Z-axis. 
		glm::mat4	view;
		// Projection matrix takes these camera coordinates and squashes them into a flat image, either using a perspective (realistic) or orthographic (non-realistic) projection
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
