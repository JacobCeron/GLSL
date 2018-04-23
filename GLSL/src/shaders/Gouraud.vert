#version 430 core

layout (location = 0) in vec3 vPos;
layout (location = 2) in vec3 vNor;

out vec3 LightIntensity;

struct LightInfo
{
	vec4 LightPosition;
	vec3 La;
	vec3 Ld;
	vec3 Ls;
};

uniform LightInfo Light;

struct MaterialInfo
{
	vec3 Ka;
	vec3 Kd;
	vec3 Ks;
	float Shininess;
};

uniform MaterialInfo Material;

uniform mat3 NormalMatrix;
uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;
uniform mat4 MVP;

void main()
{
	vec3 ambient = Light.La * Material.Ka;

	vec3 n = normalize(NormalMatrix * vNor);
	vec4 eyeCoord = ModelViewMatrix * vec4(vPos, 1.0f);
	vec3 s = normalize(vec3(Light.LightPosition - eyeCoord));
	vec3 diffuse = Light.Ld * Material.Kd * max(dot(n, s), 0.0f);

	vec3 v = normalize(-eyeCoord.xyz);
	vec3 r = reflect(-s, n);
	vec3 specular = Light.Ls * Material.Ks * pow(max(dot(r, n), 0.0f), Material.Shininess);

	LightIntensity = ambient + diffuse + specular;
	gl_Position = MVP * vec4(vPos, 1.0f);
}