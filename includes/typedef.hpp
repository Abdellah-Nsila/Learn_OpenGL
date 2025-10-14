#pragma once

#include "includes.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

typedef struct s_triangle
{
	GLfloat			vertices[9];
	// A vertex array object (also known as VAO) bind/unbind VBO's
	VAO				vao;
	//  Element Buffer Objects, that use indexed drawing
	EBO				ebo;
	// We manage this memory via so called vertex buffer objects (VBO)
	// that can store a large number of vertices in the GPU's memory
	VBO				vbo;
	// code file path to the vertex shader
	char			*vertexPath;
	// code file path to the fragment shader
	char			*fragmentPath;
	// ID reference for the shader program
	Shader			*shader;
	// ID reference for the texture program
	Texture			texture;
}				t_triangle;

typedef struct s_game
{
	int					width;
	int					height;
	GLFWwindow*			window;
	std::string			title;
}				t_game;

