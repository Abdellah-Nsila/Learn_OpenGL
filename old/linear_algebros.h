#pragma once

#include <cmath>

#define PI 3.14159265

typedef struct s_mat4
{
	float	entries[16];
}		t_mat4;

typedef struct s_vec3
{
	float	entries[3];
}		t_vec3;

t_mat4	createMatrixTransform(t_vec3 translation);
t_mat4	create_z_rotation(float angle);
t_mat4	create_y_rotation(float angle);
t_mat4	create_x_rotation(float angle);

// t_mat4	createModelTransform(t_mat4 translationMatrix, t_mat4 rotationMatrix);

float	dot(t_vec3 u, t_vec3 v);

t_vec3	normalize(t_vec3 v);

t_vec3	cross(t_vec3 u, t_vec3 v);

t_mat4	create_look_at(t_vec3 from, t_vec3 to);

t_mat4	create_prespective_projection(float fovy, float aspect, float near, float far);