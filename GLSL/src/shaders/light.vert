#version 430 core

layout (location = 0) in vec3 vPos;

struct Transforms
{
 mat4 model;
 mat4 view;
 mat4 projection;
};

uniform Transforms transforms;

void main()
{
	gl_Position = transforms.projection * transforms.view * transforms.model * vec4(vPos, 1.0f);
}