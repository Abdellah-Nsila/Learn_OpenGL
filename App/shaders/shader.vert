#version 330 core

layout (location=0) in vec3 vertexPos;
layout (location=1) in int colorIndex;

out vec3 fragmentColor;
out vec2 fragmentTexCoord;

const vec3 vertexColors[4] = vec3[](
	vec3(1.0f, 0.0f, 0.0f),
	vec3(0.0f, 1.0f, 0.0f),
	vec3(0.0f, 0.0f, 1.0f),
	vec3(1.0f, 0.0f, 1.0f)
);

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(vertexPos, 1.0f);
	fragmentColor = vertexColors[colorIndex];
	fragmentTexCoord = 0.5f * (vertexPos.xy + vec2(1.0f));
}