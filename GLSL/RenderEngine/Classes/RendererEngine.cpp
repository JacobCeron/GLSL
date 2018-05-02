#include "RendererEngine.h"

#include "GameObject.h"
#include "Camera.h"
#include "MeshRenderer.h"

void RendererEngine::InitMeshRenderer()
{
	for (size_t i = 0; i < GameObject::gameObjects.size(); i++)
	{
		MeshRenderer* mR = GameObject::gameObjects[i]->getComponent<MeshRenderer>();
		if (mR)
			mR->init();
	}
}

void RendererEngine::Renderer()
{
	for (size_t i = 0; i < GameObject::gameObjects.size(); i++)
	{
		MeshRenderer* mR = GameObject::gameObjects[i]->getComponent<MeshRenderer>();
		if (mR)
		{
			mR->material.shader.use();
			mR->material.setMatrix(1, Camera::current->getProjectionMatrix() * Camera::current->getViewMatrix() * GameObject::gameObjects[i]->transform.getWorldToLocalMatrix());
			mR->draw();
		}
	}
}