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

Matrix4x4 Transform::getLocalToWorldMatrix()
{
	localToWorldMatrix = Matrix4x4();

	localToWorldMatrix = Matrix4x4::translate(localToWorldMatrix, position);

	localToWorldMatrix = Matrix4x4::scale(localToWorldMatrix, localScale);

	if (rotation.x != 0.0f)
		localToWorldMatrix = Matrix4x4::rotate(localToWorldMatrix, radians(rotation.x), Vector3(1.0f, 0.0f, 0.0f));
	if (rotation.y != 0.0f)
		localToWorldMatrix = Matrix4x4::rotate(localToWorldMatrix, radians(rotation.y), Vector3(0.0f, 1.0f, 0.0f));
	if (rotation.z != 0.0f)
		localToWorldMatrix = Matrix4x4::rotate(localToWorldMatrix, radians(rotation.z), Vector3(0.0f, 0.0f, 1.0f));

	return localToWorldMatrix;
}

/*
Matrix4x4 Transform::getWorldToLocalMatrix()
{
	return Matrix4x4::inverse(localToWorldMatrix);
}
*/