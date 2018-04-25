#version 430 core

subroutine vec3 shadeModelType(const vec4 position, const vec3 normal);

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 vUV;
layout (location = 2) in vec3 vNor;

flat out vec3 FrontColor;
flat out vec3 BackColor;
out vec2 TexCoord;

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

layout (location = 1) uniform mat3 NormalMatrix;
layout (location = 2) uniform mat4 ModelViewMatrix;
layout (location = 3) uniform mat4 MVP;

uniform vec3 eye;

subroutine uniform shadeModelType shadeModel;

void getEyeSpace(out vec4 position, out vec3 normal)
{
	normal = normalize(transpose(inverse(NormalMatrix)) * vNor);
	position = ModelViewMatrix * vec4(vPos, 1.0f);
}

subroutine(shadeModelType)
vec3 phongModel(const vec4 position, const vec3 normal)
{
	vec3 ambient = Light.La * Material.Ka;

	vec3 s = normalize(vec3(Light.LightPosition - position));
	vec3 diffuse = Light.Ld * Material.Kd * max(dot(normal, s), 0.0f);

	vec3 v = normalize(-position.xyz);
	vec3 r = reflect(-s, normal);
	vec3 specular = Light.Ls * Material.Ks * pow(max(dot(r, v), 0.0f), Material.Shininess);

	return ambient + diffuse + specular;
}

subroutine(shadeModelType)
vec3 diffuseModel(const vec4 position, const vec3 normal)
{
	vec3 ambient = Light.La * Material.Ka;

	vec3 s = normalize(vec3(Light.LightPosition - position));
	vec3 diffuse = Light.Ld * Material.Kd * max(dot(normal, s), 0.0f);

	return ambient + diffuse;
}

void main()
{
	vec4 eyePos;
	vec3 eyeNor;

	getEyeSpace(eyePos, eyeNor);

	FrontColor = shadeModel(eyePos, eyeNor);
	BackColor = shadeModel(eyePos, -eyeNor);

	TexCoord = vUV;

	gl_Position = MVP * vec4(vPos, 1.0f);
}