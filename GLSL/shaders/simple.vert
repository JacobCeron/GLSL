#version 430 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 vUV;
layout (location = 2) in vec3 vNor;

uniform mat4 MVP;

out vec3 col;

void main()
{
	col = vec3(vPos);
	gl_Position = MVP * vec4(vPos, 1.0f);
}