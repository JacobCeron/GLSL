#version 430 core

in vec3 Nor;
in vec3 FragPos;
in vec3 col;

uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 color;

out vec4 fColor;

void main()
{
	float ambientFactor = 0.1f;
	vec3 ambient = ambientFactor * lightColor;

	vec3 norm = normalize(Nor);
	vec3 light = normalize(lightPos - FragPos);
	float diffuseFactor = max(dot(light, norm), 0);
	vec3 diffuse = diffuseFactor * lightColor;

	vec3 result = (ambient + diffuse) * color;

	fColor = vec4(result, 1.0f);
}