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

	void setFloat(const char* name, float value);
	void setFloat(unsigned int name, float value);
	void setVector(const char* name, const Vector2& vector);
	void setVector(unsigned int name, const Vector2& vector);
	void setVector(const char* name, const Vector3& vector);
	void setVector(unsigned int name, const Vector3& vector);
	void setVector(const char* name, const Vector4& vector);
	void setVector(unsigned int name, const Vector4& vector);
	void setMatrix(const char* name, const Matrix3x3& matrix);
	void setMatrix(unsigned int name, const Matrix3x3& matrix);
	void setMatrix(const char* name, const Matrix4x4& matrix);
	void setMatrix(unsigned int name, const Matrix4x4& matrix);
	void setSubroutine(const char* name, Shader::ShaderType type);
	//void setSubrutine(const char* nameSubroutine, const char* name, Shader::ShaderType type);

	void setMatrix(const char* name, const glm::mat4& matrix);
};