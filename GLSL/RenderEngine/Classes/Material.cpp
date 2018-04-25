#include "Material.h"

Material::Material()
{

}

Material::Material(const Shader& s)
	: shader{ s }
{

}

Material::Material(const Material& copy)
	: Material{ copy.shader }
{

}

void Material::setFloat(const char* name, float value)
{
	shader(name, value);
}

void Material::setVector(const char* name, const Vector2& vector)
{
	shader(name, vector);
}

void Material::setVector(const char* name, const Vector3& vector)
{
	shader(name, vector);
}

void Material::setVector(const char* name, const Vector4& vector)
{
	shader(name, vector);
}

void Material::setMatrix(const char* name, const Matrix3x3& matrix)
{
	shader(name, matrix);
}

void Material::setMatrix(const char* name, const Matrix4x4& matrix)
{
	shader(name, matrix);
}