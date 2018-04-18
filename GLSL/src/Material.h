#pragma once

#include "Shader.h"

class Material
{
public:
	Shader shader;

public:
	Material();
	Material(const Shader& shader);
	Material(const Material& copy);

	void setVector2(const char* name, const glm::vec2& vector);
	void setVector3(const char* name, const glm::vec3& vector);
	void setVector4(const char* name, const glm::vec4& vector);
	void setMatrix4x4(const char* name, const glm::mat4& matrix);
};