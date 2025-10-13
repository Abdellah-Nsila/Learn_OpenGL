#pragma once

#include "includes.hpp"

class Shader
{
	public:
		unsigned int	ID;
	public:
		Shader();
		// Constructor reads and builds the shader
		Shader(const char *vertexPath, const char *fragmentPath);
		~Shader();
		// use/activate the shader
		void	useProgram();
		void	deleteProgram() ;
		// utility uniform functions
		void	setBool(const std::string &name, bool value) const;  
		void	setInt(const std::string &name, int value) const;   
		void	setFloat(const std::string &name, GLfloat value) const;
	private:
		// Helper for custom constructor
		int				checkCompileErrors(unsigned int shader, std::string type);
		std::string		getShaderCode(int SHADER_TYPE, const char *path);
		unsigned int	compileShader(int SHADER_TYPE, const char *vShaderCode);
		unsigned int	createShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);
};
