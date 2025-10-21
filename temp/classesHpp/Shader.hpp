#pragma once

#include "core/Engine.hpp"

class Shader
{
	public:
		GLuint	ID;
	public:
		Shader();
		// Constructor reads and builds the shader
		Shader(const char *vertexPath, const char *fragmentPath);
		~Shader();
		// use/activate the shader
		void	useProgram();
		void	deleteProgram() ;
		// utility uniform functions
		void	setBool(const std::string &name, GLboolean value) const;  
		void	setInt(const std::string &name, GLint value) const;   
		void	setFloat(const std::string &name, GLfloat value) const;
		void	setVec2(const std::string &name, const glm::vec2 &value) const;
		void	setVec2(const std::string &name, GLfloat x, GLfloat y) const;
		void	setVec3(const std::string &name, const glm::vec3 &value) const;
		void	setVec3(const std::string &name, GLfloat x, GLfloat y, GLfloat z) const;
		void	setVec4(const std::string &name, const glm::vec4 &value) const;
		void	setVec4(const std::string &name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) const;
		void	setMat2(const std::string &name, const glm::mat2 &mat) const;
		void	setMat3(const std::string &name, const glm::mat3 &mat) const;
		void	setMat4(const std::string &name, const glm::mat4 &mat) const;
	private:
		// Helper for custom constructor
		int				checkCompileErrors(GLuint shader, std::string type);
		std::string		getShaderCode(int SHADER_TYPE, const char *path);
		GLuint	compileShader(int SHADER_TYPE, const char *vShaderCode);
		GLuint	createShaderProgram(GLuint vertexShader, GLuint fragmentShader);
};
