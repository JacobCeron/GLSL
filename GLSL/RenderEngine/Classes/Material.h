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
	void setVector2(const char* name, const Vector2& vector);
	void setVector3(const char* name, const Vector3& vector);
	void setVector4(const char* name, const Vector4& vector);
	void setMatrix3x3(const char* name, const Matrix3x3& matrix);
	void setMatrix4x4(const char* name, const Matrix4x4& matrix);
};