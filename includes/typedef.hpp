#pragma once

#include "includes.hpp"
#include "Shader.hpp"

typedef struct s_triangle
{
	float			vertices[9];
	// A vertex array object (also known as VAO) bind/unbind VBO's
	unsigned int	VAO;
	//  Element Buffer Objects, that use indexed drawing
	unsigned int	EBO;
	// We manage this memory via so called vertex buffer objects (VBO)
	// that can store a large number of vertices in the GPU's memory
	unsigned int	VBO;
	// code file path to the vertex shader
	char			*vertexPath;
	// code file path to the fragment shader
	char			*fragmentPath;
	// ID reference for the shader program
	Shader			*shader;
}				t_triangle;

typedef struct s_game
{
	int					width;
	int					height;
	GLFWwindow*			window;
	std::string			title;
	t_triangle			t[2];
}				t_game;

