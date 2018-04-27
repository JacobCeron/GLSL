#version 430 core

in vec3 FragmentPosition;
in vec3 Normal;

out vec4 FragmentColor;

struct LightProperties
{
	vec3 Position;
	vec3 La;
	vec3 Ld;
	vec3 Ls;
};

struct MaterialProperties
{
	vec3 Ka;
	vec3 Kd;
	vec3 Ks;
	float Shininess;
};

uniform LightProperties Light; 
uniform MaterialProperties Material;
uniform float levels;

vec3 celModel(vec3 FragmentPosition, vec3 Normal)
{
	vec3 ambient = Light.La * Material.Ka;

	vec3 N = normalize(Normal);
	vec3 L = normalize(Light.Position - FragmentPosition);

	float cosine = max(dot(L, N), 0.0f);
	float scaleLevels = 1.0f / levels;
	vec3 diffuse = Light.Ld * (floor(cosine * levels) * scaleLevels * Material.Kd);

	return ambient + diffuse;
}

void main()
{
	vec3 lightColor = celModel(FragmentPosition, Normal);
	FragmentColor = vec4(lightColor, 1.0f);
}