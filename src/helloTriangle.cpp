#include "game.hpp"

// 3D Vertices cordinations of triangle (x, y, z) 
float	vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};

// The source code for the vertex shader written in GLSL (OpenGL Shading Language)
const char	*vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char	*fragmentShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"} \n";

// Creating memory on the GPU where we store the vertex data
int	vertex_input()
{
	// A vertex array object (also known as VAO) bind/unbind VBO's
	unsigned int	VAO;
	// We manage this memory via so called vertex buffer objects (VBO)
	// that can store a large number of vertices in the GPU's memory
	unsigned int	VBO;

	// Generate a VAO
	glGenVertexArrays(1, &VAO);
	// Generate a buffer has with the unique ID &VBO
	glGenBuffers(1, &VBO);
	// Bind Vertex Array Object
	glBindVertexArray(VAO);
	// Bind the newly created buffer to the GL_ARRAY_BUFFER target
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Copie the previously defined vertex data into the buffer's memory
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// Tell OpenGL how it should interpret the vertex data (per vertex attribute)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// Enable the vertex attribute with glEnableVertexAttribArray giving the vertex attribute location as its argument
	glEnableVertexAttribArray(0);
	// Unbind Vertex Array Object
	glBindVertexArray(VAO);
	return (EXIT_SUCCESS);

}

unsigned int	vertex_shader()
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
		return (0);
	}
	return (vertexShader);
}

unsigned int	fragment_shader()
{
	// ID for the shader object
	unsigned int	fragmentShader;
	// Track compile status and logs
	int 			success;
	char			infoLog[512];

	// Create a shader object, again referenced by an ID
	fragmentShader =  glCreateShader(GL_FRAGMENT_SHADER);
	// Attach the shader source code to the shader object and compile the shader
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// Checking for compile-time errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		return (0);
	}
	return (fragmentShader);
}

unsigned int	shader_program()
{
	// ID's references
	unsigned int	vertexShader;
	unsigned int	fragmentShader;
	unsigned int	shaderProgram;
	// Track compile status and logs
	int 			success;
	char			infoLog[512];

	vertexShader = vertex_shader();
	if (!vertexShader)
		return (0);
	fragmentShader = fragment_shader();
	if (!fragmentShader)
	{
		glDeleteShader(vertexShader);
		return (0);
	}
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
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM:COMPILATION_FAILED\n" << infoLog << std::endl;
		return (0);
	}
	return (shaderProgram);
}

int	use_program()
{
	// ID reference for shader program
	unsigned int	shaderProgram;
	
	shaderProgram = shader_program();
	// Every shader and rendering call after glUseProgram will now use this program object
	glUseProgram(shaderProgram);
	// Draws primitives using the currently active shader, the previously defined vertex attribute configuration
	// and with the VBO's vertex data (indirectly bound via the VAO)
	glDrawArrays(GL_TRIANGLES, 0, 3);
	return (EXIT_SUCCESS);
}
