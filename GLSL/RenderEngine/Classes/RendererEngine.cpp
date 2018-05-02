#include "RendererEngine.h"

#include "GameObject.h"
#include "Camera.h"
#include "DirectionalLight.h"
#include "MeshRenderer.h"

#include <iostream>

void RendererEngine::InitMeshRenderer()
{
	for (size_t i = 0; i < GameObject::gameObjects.size(); i++)
	{
		MeshRenderer* mR = GameObject::gameObjects[i]->getComponent<MeshRenderer>();
		if (mR)
			mR->init();
	}
}

void RendererEngine::UseShader()
{
	for (size_t i = 0; i < GameObject::gameObjects.size(); i++)
	{
		MeshRenderer* mR = GameObject::gameObjects[i]->getComponent<MeshRenderer>();
		if (mR)
			mR->material.shader.use();
	}
}

void RendererEngine::Renderer()
{
	for (size_t i = 0; i < GameObject::gameObjects.size(); i++)
	{
		MeshRenderer* mR = GameObject::gameObjects[i]->getComponent<MeshRenderer>();
		if (mR)
		{
			mR->material.setMatrix(1, GameObject::gameObjects[i]->transform.getWorldToLocalMatrix());
			if (Camera::currentCamera)
				TransformMatrices(mR);
			mR->material.setInt(12, DirectionalLight::currentLights.size());
			for (size_t i{ 0 }; i < DirectionalLight::currentLights.size(); i++)
				DirectionalLights(mR, i);
			mR->draw();
		}
	}
}

void RendererEngine::TransformMatrices(MeshRenderer* meshRenderer)
{
	meshRenderer->material.setMatrix(2, Camera::currentCamera->getViewMatrix());
	meshRenderer->material.setMatrix(3, Camera::currentCamera->getProjectionMatrix());
}

void RendererEngine::DirectionalLights(MeshRenderer* meshRenderer, size_t index)
{
	meshRenderer->material.setVector(std::string("light[" + std::to_string(index) + "].Direction").c_str(), DirectionalLight::currentLights[index]->gameObject->transform.rotation);
	meshRenderer->material.setVector(std::string("light[" + std::to_string(index) + "].Color").c_str(), DirectionalLight::currentLights[index]->getColor());
}