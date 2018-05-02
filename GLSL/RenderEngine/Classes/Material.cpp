#include "Material.h"

Material::Material()
{}

Material::Material(const Shader& s)
	: shader{ s }
{}

Material::Material(const Material& copy)
	: Material{ copy.shader }
{}

void Material::setInt(const char* name, int value)
{
	shader(name, value);
}

void Material::setInt(unsigned int name, int value)
{
	shader(name, value);
}

void Material::setFloat(const char* name, float value)
{
	shader(name, value);
}

void Material::setFloat(unsigned int name, float value)
{
	shader(name, value);
}

void Material::setVector(const char* name, const Vector2& vector)
{
	shader(name, vector);
}

void Material::setVector(unsigned int name, const Vector2 & vector)
{
	shader(name, vector);
}

void Material::setVector(const char* name, const Vector3& vector)
{
	shader(name, vector);
}

void Material::setVector(unsigned int name, const Vector3 & vector)
{
	shader(name, vector);
}

void Material::setVector(const char* name, const Vector4& vector)
{
	shader(name, vector);
}

void Material::setVector(unsigned int name, const Vector4 & vector)
{
	shader(name, vector);
}

void Material::setMatrix(const char* name, const Matrix3x3& matrix)
{
	shader(name, matrix);
}

void Material::setMatrix(unsigned int name, const Matrix3x3 & matrix)
{
	shader(name, matrix);
}

void Material::setMatrix(const char* name, const Matrix4x4& matrix)
{
	shader(name, matrix);
}

void Material::setMatrix(unsigned int name, const Matrix4x4 & matrix)
{
	shader(name, matrix);
}

void Material::setSubroutine(const char* name, Shader::ShaderType type)
{
	shader(name, type);
}

void Material::setMatrix(const char* name, const glm::mat4& matrix)
{
	shader(name, matrix);
}