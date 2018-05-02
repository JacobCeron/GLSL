#version 430 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 vUV;
layout (location = 2) in vec3 vNor;

out vec3 color;

layout (location = 1) uniform mat4 PVM;

void main()
{
	color = vNor;
	gl_Position = PVM * vec4(vPos, 1.0f);
}