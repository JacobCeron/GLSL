#pragma once

#include "MeshRenderer.h"

class RendererEngine
{
public:
	void InitMeshRenderer();
	void UseShader();
	void Renderer();

private:
	void TransformMatrices(MeshRenderer* meshRenderer);
	void DirectionalLights(MeshRenderer* meshRenderer, size_t index);
};