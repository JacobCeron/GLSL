#include "Camera.h"
#include "GameObject.h"
#include <iostream>

Camera* Camera::current{ nullptr };

Camera::Camera()
{
	orthographic = true;
	current = this;
}

Matrix4x4 Camera::getViewMatrix()
{
	/*Vector3 eye(gameObject->transform.position);
	Vector3 target(-Vector3::forward);
	if (gameObject->transform.rotation != Vector3(0.0f))
		target = Vector3::normalize(gameObject->transform.rotation);
	ViewMatrix = Matrix4x4::lookAt(eye, eye + target, Vector3::up);*/

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
		// ProjectionMatrix = Matrix4x4::perspective();
	return ProjectionMatrix;
}