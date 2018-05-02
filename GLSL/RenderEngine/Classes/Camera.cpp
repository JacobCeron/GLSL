#include "Camera.h"
#include "GameObject.h"
#include <iostream>

Camera* Camera::currentCamera{ nullptr };

Camera::Camera()
{
	orthographic = true;
	currentCamera = this;
}

Matrix4x4 Camera::getViewMatrix()
{
	ViewMatrix = gameObject->transform.getWorldToLocalMatrix();
	ViewMatrix[3][0] *= -1;
	ViewMatrix[3][1] *= -1;
	ViewMatrix[3][2] *= -1;

	return ViewMatrix;
}

void Camera::setProjectionMatrix(const Matrix4x4 & projection)
{
	ProjectionMatrix = projection;
}

Matrix4x4 Camera::getProjectionMatrix()
{
	if (orthographic)
		ProjectionMatrix = Matrix4x4::ortho(-6.0f, 6.0f, -6.0f, 6.0f, 0.0f, 600.0f);
	else
		return ProjectionMatrix;//ProjectionMatrix = Matrix4x4::perspective();
	return ProjectionMatrix;
}