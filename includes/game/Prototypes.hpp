#pragma once

#include "Types.hpp"

// Init
int		setup_setting(t_game game);
int		init_window(t_game game);
int		init_events(t_game game);
int		init_engine(t_game *game);

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
int				render(t_game *game);
void			destroyPipeline(t_triangle *t);