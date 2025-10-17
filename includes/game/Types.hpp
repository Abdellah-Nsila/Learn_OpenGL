#pragma once

#include <string>
#include "classes/VAO.hpp"
#include "classes/VBO.hpp"
#include "classes/EBO.hpp"
#include "classes/Shader.hpp"
#include "classes/Texture.hpp"

extern float			transparent;

extern GLfloat			lastX;
extern GLfloat			lastY;

extern GLboolean		firstMouse;

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
	Texture			texture[2];
}				t_triangle;

typedef struct s_game
{
	GLfloat				width;
	GLfloat				height;
	GLFWwindow*			window;
	std::string			title;
	Camera				camera;
}				t_game;

extern t_game			game;
