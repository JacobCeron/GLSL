#pragma once

#include "Behaviour.h"
#include "Maths.h"

class Camera
	: public Behaviour
{
public:
	static Camera* current;
private:
	Matrix4x4 ViewMatrix;
	Matrix4x4 ProjectionMatrix;
	
public:
	Camera();

	Matrix4x4 getViewMatrix();
	void setProjectionMatrix(const Matrix4x4& projection);
	Matrix4x4 getProjectionMatrix();
};