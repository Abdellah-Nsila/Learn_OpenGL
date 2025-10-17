#pragma once

#include "Types.hpp"

// Init
int		setup_setting();
int		init_window();
int		init_events();
int		init_engine();

// Events
void	key_callback(GLFWwindow* window);
void	mouse_callback(GLFWwindow* window, double xpos, double ypos);
void	scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

// int				vertex_input(t_triangle *t);
// int				vertex_input(t_triangle *t, GLfloat vertices[9], size_t size);
// int				shader_program(t_triangle *t);
// int				setup_shaders(t_triangle *t);
// int				setup_shaders(t_triangle *t, GLfloat vertices[9], size_t size);

// Render
int				setupPipeline(t_triangle *t);
int				drawTriangle(t_triangle *t, int idx);
int				render();
void			destroyPipeline(t_triangle *t);