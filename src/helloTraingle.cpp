#include "game.hpp"

// 3D Vertices cordinations of triangle (x, y, z) 
float	vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};

// The source code for the vertex shader written in GLSL (OpenGL Shading Language)
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

// Creating memory on the GPU where we store the vertex data
int	vertex_input()
{
	// We manage this memory via so called vertex buffer objects (VBO)
	// that can store a large number of vertices in the GPU's memory
	unsigned int	VBO;

	// Generate a buffer has with the unique ID &VBO
	glGenBuffers(1, &VBO);
	// Bind the newly created buffer to the GL_ARRAY_BUFFER target
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Copie the previously defined vertex data into the buffer's memory
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	return (EXIT_SUCCESS);

}

int	vertex_shader()
{
	// ID for the shader object
	unsigned int	vertexShader;
	// Track compile status and logs
	int 			success;
	char			infoLog[512];

	// Create a shader object, again referenced by an ID
	vertexShader =  glCreateShader(GL_VERTEX_SHADER);
	// Attach the shader source code to the shader object and compile the shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// Checking for compile-time errors
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	geomatry_shader()
{
	return (EXIT_SUCCESS);
}

int	fragement_shader()
{
	return (EXIT_SUCCESS);
}


