#include <glad\glad.h>

#include "MyApplication.h"
#include "RenderEngine/Classes/Time.h"

#include <iostream>

MyApplication::MyApplication(int width, int height, const char * name)
	: CoreEngine(width, height, name)
{}

float time = 0.5f;

void MyApplication::Start()
{
	Shader shaderObj;
	shaderObj.compileShader(Shader::readShaderFile("shaders/Toon.vert").c_str(), Shader::VERTEX);
	shaderObj.compileShader(Shader::readShaderFile("shaders/Toon.frag").c_str(), Shader::FRAGMENT);
	shaderObj.linkProgram();
	renderMesh.material.shader = shaderObj;

	Mesh mesh;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/cube.obj");
	renderMesh.mesh = mesh;

	renderMesh.init();
}

void MyApplication::Update()
{
	m_window.color(Vector3(0.5f, 0.5f, 0.5f));

	time += Time::deltaTime * 60.0f;
	transform.Rotate(Vector3(6.0f, 1.0f, 0.0f));
	transform.localScale = Vector3(6.0f);

	Matrix4x4 ViewMatrix;
	ViewMatrix = Matrix4x4::lookAt(Vector3(0.0f, 0.0f, 10.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f));
	Matrix4x4 ProjectionMatrix;
	ProjectionMatrix = Matrix4x4::ortho(-10.0f, 10.0f, -10.0f, 10.0f, -60.0f, 60.0f);

	static Vector3 LightPosition(6.0f, 6.0f, 6.0f);

	renderMesh.material.shader.use();

	renderMesh.material.setMatrix(1, transform.getLocalToWorldMatrix());
	renderMesh.material.setMatrix(2, ViewMatrix);
	renderMesh.material.setMatrix(3, ProjectionMatrix);
	renderMesh.material.setVector("EyePosition", Vector3(0.0f, 0.0f, 10.0f));

	renderMesh.material.setVector("Light.Position", LightPosition);
	renderMesh.material.setVector("Light.La", Vector3(1.0f, 1.0f, 1.0f));
	renderMesh.material.setVector("Light.Ld", Vector3(1.0f, 1.0f, 1.0f));

	renderMesh.material.setVector("Material.Ka", Vector3(0.1f, 0.0f, 0.5f));
	renderMesh.material.setVector("Material.Kd", Vector3(0.25f, 0.0f, 1.0f));
	renderMesh.material.setFloat("levels", 3.0f);

	renderMesh.draw();
}