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

uniform vec3 EyePosition;
uniform LightProperties Light; 
uniform MaterialProperties Material;

vec3 phongModel(vec3 FragmentPosition, vec3 Normal)
{
	vec3 N = normalize(Normal);
	vec3 L = normalize(Light.Position - FragmentPosition);
	vec3 E = normalize(EyePosition - FragmentPosition);
	vec3 R = reflect(-L, N);

	vec3 ambient = Light.La * Material.Ka;
	vec3 diffuse = Light.Ld * (Material.Kd * max(dot(L, N), 0.0f));
	vec3 specular = Light.Ls * (Material.Ks * pow(max(dot(E, R), 0.0f), Material.Shininess));

	return ambient + diffuse + specular;
}

void main()
{
	vec3 lightColor = phongModel(FragmentPosition, Normal);
	FragmentColor = vec4(lightColor, 1.0f);
}