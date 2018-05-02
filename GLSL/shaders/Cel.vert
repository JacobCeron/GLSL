#version 430 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 vUVs;
layout (location = 2) in vec3 vNor;

out vec3 fNor;
out vec3 fPos;

layout (location = 1) uniform mat4 ModelMatrix;
layout (location = 2) uniform mat4 ViewMatrix;
layout (location = 3) uniform mat4 ProjectionMatrix;

void main()
{
	fPos = vec3(ModelMatrix * vec4(vPos, 1.0f));
	fNor = mat3(transpose(inverse(ModelMatrix))) * vNor;

	gl_Position = ProjectionMatrix * ViewMatrix * vec4(fPos, 1.0f);
}