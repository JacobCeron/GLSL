#version 430 core

in vec3 fPos;
in vec3 fNor;

out vec4 fColor;

struct Light
{
	vec3 Direction;
	vec4 Color;
};

uniform Light light[5];
layout (location = 12) uniform int numLights;

layout (location = 15) uniform vec4 mColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);

uniform float levels = 3.0f;

vec3 toonModel(vec3 FragmentPosition, vec3 Normal, int lightIndex)
{
	vec3 ambient = vec3((light[lightIndex].Color * 0.2f) * mColor);

	vec3 N = normalize(Normal);
	vec3 L = normalize(-light[lightIndex].Direction);

	float cosine = max(dot(L, N), 0.0f);
	float scaleLevels = 1.0f / levels;
	vec3 diffuse = vec3(light[lightIndex].Color * (floor(cosine * levels) * scaleLevels * mColor));

	return ambient + diffuse;
}

void main()
{
	vec3 lightColor = vec3(0.0f);
	
	for(int i = 0; i < numLights; i++)
		lightColor += toonModel(fPos, fNor, i);

	fColor = vec4(lightColor, 1.0f);
}