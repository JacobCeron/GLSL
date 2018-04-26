#version 430 core

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 VertexTexture;
layout (location = 2) in vec3 VertexNormal;

flat out vec3 color;

struct LightProperties
{
	vec3 Position;
	vec3 La;
	vec3 Ld;
	vec3 Ls;
};

struct MaterialProperties
{
	float Shininess;
};

layout (location = 1) uniform mat4 ModelMatrix;
layout (location = 2) uniform mat4 ViewMatrix;
layout (location = 3) uniform mat4 ProjectionMatrix;

uniform vec3 EyePosition;
uniform LightProperties Light;
uniform MaterialProperties Material;

vec3 phongModel(vec3 FragmentPosition, vec3 Normal)
{
	vec3 N = normalize(Normal);
	vec3 L = normalize(Light.Position - FragmentPosition);
	vec3 E = normalize(EyePosition - FragmentPosition);
	vec3 R = reflect(-L, N);

	vec3 ambient = Light.La * VertexPosition;
	vec3 diffuse = Light.Ld * (VertexPosition * max(dot(L, N), 0.0f));
	vec3 specular = Light.Ls * (VertexPosition * pow(max(dot(E, R), 0.0f), Material.Shininess));

	return ambient + diffuse + specular;
}

void main()
{
	vec3 FragmentPosition = vec3(ModelMatrix * vec4(VertexPosition, 1.0f));
	vec3 Normal = mat3(transpose(inverse(ModelMatrix))) * VertexNormal;

	color = phongModel(FragmentPosition, Normal);

	gl_Position = ProjectionMatrix * ViewMatrix * vec4(FragmentPosition, 1.0f);
}