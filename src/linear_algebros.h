#pragma once

typedef struct s_mat4
{
	float	entries[16];
}		t_mat4;

typedef struct s_vec3
{
	float	entries[3];
}		t_vec3;

t_mat4	createMatrixTransform(t_vec3 translation);
