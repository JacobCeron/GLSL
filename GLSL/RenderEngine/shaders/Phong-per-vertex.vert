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

uniform vec3 eye;

void getEyeSpace(out vec3 position, out vec3 normal)
{
	normal = normalize(transpose(inverse(NormalMatrix)) * vNor);
	position = vec3(ModelViewMatrix * vec4(vPos, 1.0f));
}

vec3 phongModel(const vec3 position, const vec3 normal)
{
	vec3 ambient = Light.La * Material.Ka;

	vec3 s = normalize(Light.LightPosition.xyz - position);
	vec3 diffuse = Light.Ld * Material.Kd * max(dot(normal, s), 0.0f);

	vec3 v = normalize(-position);
	vec3 r = reflect(-s, normal);
	vec3 specular = Light.Ls * Material.Ks * pow(max(dot(r, v), 0.0f), Material.Shininess);

	return ambient + diffuse + specular;
}

void main()
{
	vec3 eyePos;
	vec3 eyeNor;

	getEyeSpace(eyePos, eyeNor);
	LightIntensity = phongModel(eyePos, eyeNor);

	gl_Position = MVP * vec4(vPos, 1.0f);
}