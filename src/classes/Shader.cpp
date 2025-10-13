#include "game.hpp"

Shader::Shader()
{
}

Shader::~Shader()
{
}

int	Shader::checkCompileErrors(unsigned int shader, std::string type)
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
		code   = shaderStream.str();
	}
	catch(const std::ifstream::failure& e)
	{
		std::cerr << "ERROR::SHADER::"
		<< (SHADER_TYPE == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT")
		<< "::FILE_NOT_SUCCESFULLY_READ::" << e.what() << std::endl;
		return ("");
	}
		return (shaderStream.str());
}

unsigned int	Shader::compileShader(int SHADER_TYPE, const char* shaderCode)
{
	unsigned int	shaderID;

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

unsigned int	Shader::createShaderProgram(unsigned int vertexShader, unsigned int fragmentShader)
{
	unsigned int	shaderProgram;

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
	unsigned int	vertexShader, fragmentShader;

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
	glUseProgram(ID);
}

void	Shader::deleteProgram() 
{ 
	glDeleteProgram(ID);
}

void	Shader::setBool(const std::string &name, bool value) const
{         
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
}

void	Shader::setInt(const std::string &name, int value) const
{ 
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}

void	Shader::setFloat(const std::string &name, GLfloat value) const
{ 
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
}

