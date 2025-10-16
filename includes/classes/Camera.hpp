#pragma once

class Camera
{
	private:
		glm::vec3	cameraPosition;
		glm::vec3	cameraTarget;
		glm::vec3	cameraUp;
		GLfloat		cameraSpeed;
		glm::mat4	view;
		glm::mat4	projection;
		GLfloat		pitch;
		GLfloat		yaw;
		GLfloat		roll;

	public:
		Camera();
		~Camera();
		const glm::vec3&		getCameraPosition() const;
		const glm::vec3&		getCameraTarget() const;
		const glm::vec3&		getCameraUp() const;
		const GLfloat&			getCameraSpeed() const;
		const GLfloat&			getPitch() const;
		const GLfloat&			getYaw() const;
		const GLfloat&			getRoll() const;

		void	setView(glm::vec3& cameraPosition, glm::vec3& cameraTarget, glm::vec3& cameraUp);
		void	setProjection(GLfloat& fovy, GLfloat& aspect, GLfloat& near, GLfloat& far);
		void	setCameraPosition(glm::vec3& cameraPosition);
		void	setCameraTarget(glm::vec3& cameraTarget);
		void	setCameraUp(glm::vec3& cameraUp);
		void	setCameraSpeed(GLfloat& cameraSpeed);
		void	setPitch(GLfloat& pitch);
		void	setYaw(GLfloat& yaw);
		void	setRoll(GLfloat& roll);

};

