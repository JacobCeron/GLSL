#version 430 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 vUV;
layout (location = 2) in vec3 vNor;

struct Transforms
{
 mat4 model;
 mat4 view;
 mat4 projection;
};

uniform Transforms transforms;

out vec3 Nor;
out vec3 FragPos;

void main()
{
	Nor = mat3(transpose(inverse(transforms.model))) * vNor;
	FragPos = vec3(transforms.model * vec4(vPos, 1.0f));
	gl_Position = transforms.projection * transforms.view * vec4(FragPos, 1.0f);
}