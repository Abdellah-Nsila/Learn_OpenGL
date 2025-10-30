#version 330 core

in vec3 fragmentColor;
in vec2 fragmentTexCoord;

uniform sampler2D material;
uniform sampler2D mask;

out vec4 screenColor;

void main()
{
	// screenColor = vec4(fragmentColor, 1.0);
	screenColor = mix(texture(material, fragmentTexCoord), texture(mask, fragmentTexCoord), 0.3f);
}