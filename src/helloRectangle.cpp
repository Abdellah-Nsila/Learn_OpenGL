#include "game.hpp"

// 3D Vertices cordinations of triangle (x, y, z) 
float vertices[] = {
	0.5f,  0.5f, 0.0f,  // top right
	0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
};

unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
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
int	vertex_input(t_triangle *t)
{
	//! Genrate
	// Generate a VAO
	glGenVertexArrays(1, &t->VAO);
	// Generate a buffer has with the unique ID &VBO
	glGenBuffers(1, &t->VBO);
	// Generate a EBO
	glGenBuffers(1, &t->EBO);

	//! Bind VAO Vertex Array Object
	glBindVertexArray(t->VAO);

	//! Bind and Copy into VBO
	// Bind the newly created buffer to the GL_ARRAY_BUFFER target
	glBindBuffer(GL_ARRAY_BUFFER, t->VBO);
	// Copy the previously defined vertex data into the buffer's memory
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//! Bind and Copy into EBO
	// Bind Element Buffer Object
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, t->EBO);
	// Copy the indices into the buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 

	// Tell OpenGL how it should interpret the vertex data (per vertex attribute)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// Enable the vertex attribute with glEnableVertexAttribArray giving the vertex attribute location as its argument
	glEnableVertexAttribArray(0);

	//! Unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return (EXIT_SUCCESS);

}

unsigned int	vertex_shader()
{
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

int	shader_program(t_triangle *t)
{
	// Track compile status and logs
	int 			success;
	char			infoLog[512];

	t->vertexShader = vertex_shader();
	if (!t->vertexShader)
		return (0);
	t->fragmentShader = fragment_shader();
	if (!t->fragmentShader)
	{
		glDeleteShader(t->vertexShader);
		return (0);
	}
	// Creates a program and returns the ID reference to the newly created program object
	t->shaderProgram = glCreateProgram();
	// We attach the shaders to the program and link the
	glAttachShader(t->shaderProgram, t->vertexShader);
	glAttachShader(t->shaderProgram, t->fragmentShader);
	glLinkProgram(t->shaderProgram);
	// Delete the shader objects once we've linked them into the program object
	glDeleteShader(t->vertexShader);
	glDeleteShader(t->fragmentShader);
	// Checking for compile-time errors
	glGetProgramiv(t->shaderProgram, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(t->shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM:COMPILATION_FAILED\n" << infoLog << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	setup_shaders(t_triangle *t)
{

	vertex_input(t);
	if (shader_program(t) == EXIT_FAILURE)
	{
		glDeleteVertexArrays(1, &t->VAO);
    	glDeleteBuffers(1, &t->VBO);
		glDeleteBuffers(1, &t->EBO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	clean_shaders(t_triangle *t)
{
	glDeleteVertexArrays(1, &t->VAO);
    glDeleteBuffers(1, &t->VBO);
    glDeleteBuffers(1, &t->EBO);
    glDeleteProgram(t->shaderProgram);
}

int	draw_triangle(t_triangle *t)
{
	// Every shader and rendering call after glUseProgram will now use this program object
	glUseProgram(t->shaderProgram);
	glBindVertexArray(t->VAO);
	// Draws primitives using the currently active shader, the previously defined vertex attribute configuration
	// and with the VBO's vertex data (indirectly bound via the VAO)
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	return (EXIT_SUCCESS);
}
