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

void Material::setVector2(const char* name, const glm::vec2& vector)
{
	shader(name, vector);
}

void Material::setVector3(const char* name, const glm::vec3& vector)
{
	shader(name, vector);
}

void Material::setVector4(const char* name, const glm::vec4& vector)
{
	shader(name, vector);
}

void Material::setMatrix3x3(const char* name, const glm::mat3& matrix)
{
	shader(name, matrix);
}

void Material::setMatrix4x4(const char* name, const glm::mat4& matrix)
{
	shader(name, matrix);
}

/**************************************************************************************************/
void Material::setVector2(const char* name, const Vector2& vector)
{
	shader(name, vector);
}

void Material::setVector3(const char* name, const Vector3& vector)
{
	shader(name, vector);
}

void Material::setVector4(const char* name, const Vector4& vector)
{
	shader(name, vector);
}

void Material::setMatrix3x3(const char* name, const Matrix3x3& matrix)
{
	shader(name, matrix);
}

void Material::setMatrix4x4(const char* name, const Matrix4x4& matrix)
{
	shader(name, matrix);
}
/**************************************************************************************************/