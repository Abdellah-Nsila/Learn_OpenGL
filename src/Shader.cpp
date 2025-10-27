#include "config.h"
#include "Shader.hpp"
#include "linear_algebros.h"

Shader::Shader()
{
}

Shader::~Shader()
{
}

int	Shader::checkCompileErrors(GLuint shader, std::string type)
{
	int success;
	char infoLog[1024];

	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			return (EXIT_FAILURE);
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

std::string	Shader::getShaderCode(int SHADER_TYPE, const char *path)
{
	// 1. retrieve the vertex/fragment source code from filePath
	std::string			code;
	std::ifstream		shaderFile;
	std::stringstream	shaderStream;

	// ensure ifstream objects can throw exceptions:
	shaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	try 
	{
		// open files
		shaderFile.open(path);
		// read file's buffer contents into streams
		shaderStream << shaderFile.rdbuf();
		// close file handlers
		shaderFile.close();
		// convert stream into string
		code = shaderStream.str();
	}
	catch(const std::ifstream::failure& e)
	{
		std::cerr << "ERROR::SHADER::"
		<< (SHADER_TYPE == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT")
		<< "::FILE_NOT_SUCCESFULLY_READ::" << e.what() << std::endl;
		return ("");
	}
		return (code);
}

GLuint	Shader::compileShader(int SHADER_TYPE, const char* shaderCode)
{
	GLuint	shaderID;

	// Create a ID object, again referenced by an ID
	shaderID =  glCreateShader(SHADER_TYPE);
	// Attach the shader source code to the shader object and compile the shader
	glShaderSource(shaderID, 1, &shaderCode, NULL);
	glCompileShader(shaderID);
	// Checking for compile-time errors
	if (checkCompileErrors(shaderID, (SHADER_TYPE == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT")) == EXIT_FAILURE)
		return (0);
	return (shaderID);
}

GLuint	Shader::createShaderProgram(GLuint vertexShader, GLuint fragmentShader)
{
	GLuint	shaderProgram;

	// Creates a program and returns the ID reference to the newly created program object
	shaderProgram = glCreateProgram();
	// We attach the shaders to the program and link the
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// Delete the shader objects once we've linked them into the program object
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	// Checking for compile-time errors
	if (checkCompileErrors(shaderProgram, "PROGRAM") == EXIT_FAILURE)
		return (0);
	return (shaderProgram);
}

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string		vShaderCode, fShaderCode;
	GLuint			vertexShader, fragmentShader;

	// Get Souce code of Shaders using paths
	vShaderCode = getShaderCode(GL_VERTEX_SHADER, vertexPath);
	fShaderCode = getShaderCode(GL_FRAGMENT_SHADER, fragmentPath);
	if (vShaderCode.empty() || fShaderCode.empty())
		return;
	// Compile the previouse code
	vertexShader = compileShader(GL_VERTEX_SHADER, vShaderCode.c_str());
	if (!vertexShader)
		return ;
	fragmentShader = compileShader(GL_FRAGMENT_SHADER, fShaderCode.c_str());
	if (!fragmentShader)
	{
		glDeleteShader(vertexShader);
		return ;
	}
	// Create program shader
	ID = createShaderProgram(vertexShader, fragmentShader);
	if (!ID)
		return ;
}

void	Shader::useProgram() 
{ 
	if (ID)
		glUseProgram(ID);
	else
		std::cerr << "Warning: tried to use an invalid shader program\n";
}

void	Shader::deleteProgram() 
{ 
	glDeleteProgram(ID);
}

// ------------------------------------ setBool ------------------------------------
void	Shader::setBool(const std::string &name, GLboolean value) const
{         
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (GLint)value); 
}
// ------------------------------------ setInt ------------------------------------
void	Shader::setInt(const std::string &name, GLint value) const
{ 
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}
// ------------------------------------ setFloat ------------------------------------
void	Shader::setFloat(const std::string &name, GLfloat value) const
{ 
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
}
// ------------------------------------ setVec2 ------------------------------------
void	Shader::setVec2(const std::string &name, const glm::vec2 &value) const
{ 
	glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
}
void	Shader::setVec2(const std::string &name, GLfloat x, GLfloat y) const
{ 
	glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y); 
}
// ------------------------------------ setVec3 ------------------------------------
void	Shader::setVec3(const std::string &name, const glm::vec3 &value) const
{ 
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
}
void	Shader::setVec3(const std::string &name, GLfloat x, GLfloat y, GLfloat z) const
{ 
	glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z); 
}
// ------------------------------------ setVec4 ------------------------------------
void	Shader::setVec4(const std::string &name, const glm::vec4 &value) const
{ 
	glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
}
void	Shader::setVec4(const std::string &name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) const
{ 
	glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w); 
}
// ------------------------------------ setMat2 ------------------------------------
void	Shader::setMat2(const std::string &name, const glm::mat2 &mat) const
{
	GLuint	uniformLocation = glGetUniformLocation(ID, name.c_str());
	glUniformMatrix2fv(uniformLocation, 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------ setMat3 ------------------------------------
void	Shader::setMat3(const std::string &name, const glm::mat3 &mat) const
{
	GLuint	uniformLocation = glGetUniformLocation(ID, name.c_str());
	glUniformMatrix3fv(uniformLocation, 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------ setMat4 ------------------------------------
// void	Shader::setMat4(const std::string &name, const glm::mat4 &mat) const
// {
// 	GLuint	uniformLocation = glGetUniformLocation(ID, name.c_str());
// 	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &mat[0][0]);
// }
void	Shader::setMat4(const std::string &name, const t_mat4 mat) const
{
	GLuint	uniformLocation = glGetUniformLocation(ID, name.c_str());
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, mat.entries);
}