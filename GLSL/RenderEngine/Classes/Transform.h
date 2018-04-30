#pragma once

#include "Component.h"
#include "Maths.h"

class Transform
	: public Component
{
public:
	Vector3 localScale;
	Vector3 rotation;
	Vector3 position;
private:
	Matrix4x4 localToWorldMatrix;
	Matrix4x4 worldToLocalMatrix;

public:
	Transform();

	void Translate(const Vector3& translation);
	void Rotate(const Vector3& eulerAngles);
	void Scale(const Vector3& scale);

	Matrix4x4 getLocalToWorldMatrix();
//	Matrix4x4 getWorldToLocalMatrix();
};