#version 430 core

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 VertexTexture;
layout (location = 2) in vec3 VertexNormal;

out vec3 Normal;
out vec3 FragmentPosition;

layout (location = 1) uniform mat4 ModelMatrix;
layout (location = 2) uniform mat4 ViewMatrix;
layout (location = 3) uniform mat4 ProjectionMatrix;

void main()
{
	FragmentPosition = vec3(ModelMatrix * vec4(VertexPosition, 1.0f));
	Normal = mat3(transpose(inverse(ModelMatrix))) * VertexNormal;

	gl_Position = ProjectionMatrix * ViewMatrix * vec4(FragmentPosition, 1.0f);
}