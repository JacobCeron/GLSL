#pragma once

#include "Behaviour.h"
#include "Maths.h"

class Camera
	: public Behaviour
{
public:
	bool orthographic;
	static Camera* currentCamera;
private:
	Matrix4x4 ViewMatrix;
	Matrix4x4 ProjectionMatrix;
	
public:
	Camera();

	Matrix4x4 getViewMatrix();
	void setProjectionMatrix(const Matrix4x4& projection);
	Matrix4x4 getProjectionMatrix();
};