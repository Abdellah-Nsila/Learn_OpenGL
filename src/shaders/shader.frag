#version 330 core

out vec4 FragColor;
in vec3 Color;
in vec2 TexCoord;

uniform sampler2D Texture1;
uniform sampler2D Texture2;

void main()
{
	FragColor = vec4(Color, 1.0);
	// FragColor = texture(Texture1, TexCoord) * vec4(Color, 1.0);
	FragColor = mix(texture(Texture1, TexCoord), texture(Texture2, TexCoord), 0.2);
};