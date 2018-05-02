#include "Transform.h"

#include <iostream>

Transform::Transform()
{
	position = Vector3(0.0f);
	rotation = Vector3(0.0f);
	localScale = Vector3(1.0f);
}

void Transform::Translate(const Vector3& translation)
{
	position = position + translation;
}

void Transform::Rotate(const Vector3& eulerAngles)
{
	rotation = rotation + eulerAngles;
}

void Transform::Scale(const Vector3 & scale)
{
	localScale = scale;
}

/*
Matrix4x4 Transform::getLocalToWorldMatrix()
{
	return localToWorldMatrix;
}
*/

Matrix4x4 Transform::getWorldToLocalMatrix()
{
	worldToLocalMatrix = Matrix4x4();
	worldToLocalMatrix = Matrix4x4::translate(worldToLocalMatrix, position);
	worldToLocalMatrix = Matrix4x4::scale(worldToLocalMatrix, localScale);
	worldToLocalMatrix = Matrix4x4::rotate(worldToLocalMatrix, radians(rotation.x + rotation.y + rotation.z), rotation);

	return worldToLocalMatrix;
}
