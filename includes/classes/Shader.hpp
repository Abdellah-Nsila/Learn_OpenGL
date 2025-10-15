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
		void	setMat4(const std::string &name, GLsizei count, glm::mat4 trans) const;
	private:
		// Helper for custom constructor
		int				checkCompileErrors(GLuint shader, std::string type);
		std::string		getShaderCode(int SHADER_TYPE, const char *path);
		GLuint	compileShader(int SHADER_TYPE, const char *vShaderCode);
		GLuint	createShaderProgram(GLuint vertexShader, GLuint fragmentShader);
};
