#version 330 core

out vec4 FragColor;
in vec3 Color;
in vec2 TexCoord;

uniform sampler2D	Texture1;
uniform sampler2D	Texture2;
uniform float		Transparent;

uniform vec2		u_resolution; // Correctly declare the uniform
uniform float		u_time; // Correctly declare the uniform for time

vec3 pallete(float t)
{
	vec3 a = vec3(0.5, 0.5, 0.5);
	vec3 b = vec3(0.5, 0.5, 0.5);
	vec3 c = vec3(1.0, 1.0, 1.0);
	vec3 d = vec3(0.263, 0.416, 0.557);

	return (a + (b * cos(6.28318 * (c*t+d))));
}

void main()
{
	vec2 uv = (gl_FragCoord.xy * 2.0 - u_resolution.xy) / u_resolution.y;
	vec2 uv0 = uv;
	vec3 finalColor = vec3(0.0);

	for(float i = 0.0; i < 4.0; i++)
	{	
		uv = fract(uv * 1.5) - 0.5;

		float d = length(uv) * exp(-length(uv0));
		vec3 col = pallete(length(uv0) + i * 4.0 + u_time);

		d = sin(d * 8.0 + u_time) / 8.0;
		d = abs(d);
		d = pow(0.01 / d, 2.0);

		finalColor += col * d;
	}

	FragColor = mix(texture(Texture1, TexCoord), texture(Texture2, TexCoord), Transparent)
	* vec4(finalColor, 1.0);
}