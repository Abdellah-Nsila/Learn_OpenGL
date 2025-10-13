#pragma once

#include "includes.hpp"
#include "typedef.hpp"
#include "settings.hpp"
#include "init.hpp"
#include "events.hpp"

// int				vertex_input(t_triangle *t);
int				vertex_input(t_triangle *t, float vertices[9], size_t size);
// int				shader_program(t_triangle *t);
// int				setup_shaders(t_triangle *t);
// int				setup_shaders(t_triangle *t, float vertices[9], size_t size);
int				draw_triangle(t_triangle *t);
void			clean_shaders(t_triangle *t);
