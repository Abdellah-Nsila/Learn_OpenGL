#include "linear_algebros.h"

t_mat4	createMatrixTransform(t_vec3 translation)
{
	t_mat4	matrix;

	matrix.entries[0] = 1.0f;
	matrix.entries[1] = 0.0f;
	matrix.entries[2] = 0.0f;
	matrix.entries[3] = 0.0f;

	matrix.entries[4] = 0.0f;
	matrix.entries[5] = 1.0f;
	matrix.entries[6] = 0.0f;
	matrix.entries[7] = 0.0f;

	matrix.entries[8] = 0.0f;
	matrix.entries[9] = 0.0f;
	matrix.entries[10] = 1.0f;
	matrix.entries[11] = 0.0f;

	matrix.entries[12] = translation.entries[0];
	matrix.entries[13] = translation.entries[1];
	matrix.entries[14] = translation.entries[2];
	matrix.entries[15] = 1.0f;

	return (matrix);
}

t_mat4	create_z_rotation(float angle)
{
	float	radiant = angle * (PI / 180.0f);
	float	c = cos(radiant);
	float	s = sin(radiant);
	t_mat4	matrix;

	matrix.entries[0] = c;
	matrix.entries[1] = s;
	matrix.entries[2] = 0.0f;
	matrix.entries[3] = 0.0f;

	matrix.entries[4] = -s;
	matrix.entries[5] = c;
	matrix.entries[6] = 0.0f;
	matrix.entries[7] = 0.0f;

	matrix.entries[8] = 0.0f;
	matrix.entries[9] = 0.0f;
	matrix.entries[10] = 1.0f;
	matrix.entries[11] = 0.0f;

	matrix.entries[12] = 0.0f;
	matrix.entries[13] = 0.0f;
	matrix.entries[14] = 0.0f;
	matrix.entries[15] = 1.0f;

	return (matrix);
}

t_mat4	create_y_rotation(float angle)
{
	float	radiant = angle * (PI / 180.0f);
	float	c = cos(radiant);
	float	s = sin(radiant);
	t_mat4	matrix;

	matrix.entries[0] = c;
	matrix.entries[1] = 0.0f;
	matrix.entries[2] = s;
	matrix.entries[3] = 0.0f;

	matrix.entries[4] = 0.0f;
	matrix.entries[5] = 1.0f;
	matrix.entries[6] = 0.0f;
	matrix.entries[7] = 0.0f;

	matrix.entries[8] = -s;
	matrix.entries[9] = 0.0f;
	matrix.entries[10] = c;
	matrix.entries[11] = 0.0f;

	matrix.entries[12] = 0.0f;
	matrix.entries[13] = 0.0f;
	matrix.entries[14] = 0.0f;
	matrix.entries[15] = 1.0f;

	return (matrix);
}

t_mat4	create_x_rotation(float angle)
{
	float	radiant = angle * (PI / 180.0f);
	float	c = cos(radiant);
	float	s = sin(radiant);
	t_mat4	matrix;

	matrix.entries[0] = 1.0f;
	matrix.entries[1] = 0.0f;
	matrix.entries[2] = 0.0f;
	matrix.entries[3] = 0.0f;

	matrix.entries[4] = 0.0f;
	matrix.entries[5] = c;
	matrix.entries[6] = -s;
	matrix.entries[7] = 0.0f;

	matrix.entries[8] = 0.0f;
	matrix.entries[9] = s;
	matrix.entries[10] = c;
	matrix.entries[11] = 0.0f;

	matrix.entries[12] = 0.0f;
	matrix.entries[13] = 0.0f;
	matrix.entries[14] = 0.0f;
	matrix.entries[15] = 1.0f;

	return (matrix);
}

float	dot(t_vec3 u, t_vec3 v)
{
	return ( (u.entries[0] * v.entries[0])
		+ (u.entries[1] * v.entries[1])
		+ (u.entries[2] * v.entries[2]));
}

t_vec3	normalize(t_vec3 v)
{
	t_vec3	normalized_v;
	float	v_length;

	// For 2D vector: v*v = (v.x * v.x) + (v.y * v.y)
	// v*v = pow(v.x, 2) + pow(v.y, 2)
	// v*v = dot(v,v)
	v_length = sqrtf(dot(v,v));
	normalized_v.entries[0] = v.entries[0] / v_length;
	normalized_v.entries[1] = v.entries[1] / v_length;
	normalized_v.entries[2] = v.entries[2] / v_length;
	return (normalized_v);
}

t_vec3	cross(t_vec3 u, t_vec3 v)
{
	t_vec3	cross_product;

	cross_product.entries[0] = (u.entries[1] * v.entries[2]) - (u.entries[2] * v.entries[1]);
	cross_product.entries[1] = (u.entries[2] * v.entries[0]) - (u.entries[0] * v.entries[2]);
	cross_product.entries[2] = (u.entries[0] * v.entries[1]) - (u.entries[1] * v.entries[0]);

	return (cross_product);
}

t_vec3	sub(t_vec3 u, t_vec3 v)
{
	t_vec3	vec;

	vec.entries[0] = u.entries[0] - v.entries[0];
	vec.entries[1] = u.entries[1] - v.entries[1];
	vec.entries[2] = u.entries[2] - v.entries[2];
	return (vec);
}

t_mat4	create_look_at(t_vec3 from, t_vec3 to)
{
	t_mat4	matrix;
	t_vec3	global_up = {0.0f, 1.0f, 0.0f};

	t_vec3	front = normalize(sub(to, from));
	t_vec3	right = normalize(cross(front, global_up));
	t_vec3	up = cross(right, front);

	matrix.entries[0] = right.entries[0];
	matrix.entries[1] = up.entries[0];
	matrix.entries[2] = -front.entries[0];
	matrix.entries[3] = 0.0f;

	matrix.entries[4] = right.entries[1];
	matrix.entries[5] = up.entries[1];
	matrix.entries[6] = -front.entries[1];
	matrix.entries[7] = 0.0f;

	matrix.entries[8] = right.entries[2];
	matrix.entries[9] = up.entries[2];
	matrix.entries[10] = -front.entries[2];
	matrix.entries[11] = 0.0f;

	matrix.entries[12] = -dot(right, from);
	matrix.entries[13] = -dot(up, from);
	matrix.entries[14] = dot(front, from);
	matrix.entries[15] = 1.0f;

	return (matrix);
}

t_mat4	create_prespective_projection(float fovy, float aspect, float near, float far)
{
	float	tanHalfFovy = tan((fovy * (PI / 180.0f)) / 2.0f);
	t_mat4	matrix;

	matrix.entries[0] = 1.0f / (aspect * tanHalfFovy);
	matrix.entries[1] = 0.0f;
	matrix.entries[2] = 0.0f;
	matrix.entries[3] = 0.0f;

	matrix.entries[4] = 0.0f;
	matrix.entries[5] = 1.0f / tanHalfFovy;
	matrix.entries[6] = 0.0f;
	matrix.entries[7] = 0.0f;

	matrix.entries[8] = 0.0f;
	matrix.entries[9] = 0.0f;
	matrix.entries[10] = -(far - near) / (far + near);
	matrix.entries[11] = -1.0f;

	matrix.entries[12] = 0.0f;
	matrix.entries[13] = 0.0f;
	matrix.entries[14] = -(2.0f * far * near) / (far - near);
	matrix.entries[15] = 1.0f;

	return (matrix);
}
