#include "Camera.h"
#include "GameObject.h"
#include <iostream>

Camera* Camera::current{ nullptr };

Camera::Camera()
{
	current = this;
}

Matrix4x4 Camera::getViewMatrix()
{
	ViewMatrix = Matrix4x4::lookAt(gameObject->transform.position, gameObject->transform.position + (-Vector3::forward), Vector3::up);
	return ViewMatrix;
}

void Camera::setProjectionMatrix(const Matrix4x4 & projection)
{
	ProjectionMatrix = projection;
}

Matrix4x4 Camera::getProjectionMatrix()
{
	ProjectionMatrix = Matrix4x4::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);
	return ProjectionMatrix;
}