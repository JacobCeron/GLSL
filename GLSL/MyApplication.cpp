#include <glad\glad.h>

#include "MyApplication.h"
#include "RenderEngine/Classes/Time.h"
#include "RenderEngine/Classes/Camera.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <iostream>

MyApplication::MyApplication(int width, int height, const char * name)
	: CoreEngine(width, height, name)
{}

RenderMesh* renderMesh;
Camera* cam;


void MyApplication::Start()
{
	Shader shaderObj;
	shaderObj.compileShader(Shader::readShaderFile("shaders/Interpolation.vert").c_str(), Shader::VERTEX);
	shaderObj.compileShader(Shader::readShaderFile("shaders/Interpolation.frag").c_str(), Shader::FRAGMENT);
	shaderObj.linkProgram();
	Mesh mesh;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/torus.obj");

	renderMesh = mainObj.addComponent<RenderMesh>();
	renderMesh->mesh = mesh;
	renderMesh->material.shader = shaderObj;
	renderMesh->init();

	camera.transform.Translate(Vector3(0.0f, 0.0f, -3.0f));
	camera.transform.localScale = Vector3(1.0f);
	cam = camera.addComponent<Camera>();
}

void MyApplication::Update()
{
	m_window.color(Vector3(0.5f, 0.5f, 0.5f));

	renderMesh->material.shader.use();
	renderMesh->material.setMatrix(1, Camera::current->getProjectionMatrix() * Camera::current->getViewMatrix() * mainObj.transform.getWorldToLocalMatrix());
	renderMesh->draw();
}