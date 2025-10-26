#version 330 core

in vec3 fragmentColor;
in vec2 fragmentTexCoord;

uniform sampler2D material;

out vec4 screenColor;

void main()
{
	// screenColor = vec4(fragmentColor, 1.0);
	screenColor = texture(material, fragmentTexCoord);
}