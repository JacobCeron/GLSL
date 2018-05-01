#include <glad\glad.h>

#include "MyApplication.h"
#include "RenderEngine/Classes/Time.h"
#include "RenderEngine/Classes/Camera.h"

#include <iostream>

MyApplication::MyApplication(int width, int height, const char * name)
	: CoreEngine(width, height, name)
{}

RenderMesh* renderMesh;
Camera* camera;
float time{ 0.5f };
float speed{ 6.0f };

float yaw{ 0.0f };
float pitch{ 0.0f };
float spedd{ 2.0f };

void MyApplication::Start()
{
	Shader shaderObj;
	shaderObj.compileShader(Shader::readShaderFile("shaders/Toon.vert").c_str(), Shader::VERTEX);
	shaderObj.compileShader(Shader::readShaderFile("shaders/Toon.frag").c_str(), Shader::FRAGMENT);
	shaderObj.linkProgram();
	Mesh mesh;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/torus.obj");

	renderMesh = mainObj.addComponent<RenderMesh>();
	renderMesh->mesh = mesh;
	renderMesh->material.shader = shaderObj;
	renderMesh->init();

	mainCamera.addComponent<Camera>();
	mainCamera.transform.position = Vector3(0.0f, 0.0f, -10.0f);
}

void MyApplication::Update()
{
	m_window.color(Vector3(0.5f, 0.5f, 0.5f));

	mainObj.transform.Rotate(Vector3(Time::deltaTime * 60.0f, Time::deltaTime * 60.0f, 0.0f));
	mainObj.transform.localScale = Vector3(3.0f);

	if (Input::getKey(KeyCode::A))
		mainCamera.transform.Translate(-Vector3::right * Time::deltaTime * speed);
	if (Input::getKey(KeyCode::D))
		mainCamera.transform.Translate(Vector3::right * Time::deltaTime * speed);
	if (Input::getKey(KeyCode::S))
		mainCamera.transform.Translate(-Vector3::forward * Time::deltaTime * speed);
	if (Input::getKey(KeyCode::W))
		mainCamera.transform.Translate(Vector3::forward * Time::deltaTime * speed);

	static Vector3 LightPosition(6.0f, 6.0f, 6.0f);

	renderMesh->material.shader.use();
	renderMesh->material.setMatrix(1, mainObj.transform.getLocalToWorldMatrix());
	renderMesh->material.setMatrix(2, Camera::current->getViewMatrix());
	renderMesh->material.setMatrix(3, Camera::current->getProjectionMatrix());
	renderMesh->material.setVector("EyePosition", Camera::current->gameObject->transform.position);
	renderMesh->material.setVector("Light.Position", LightPosition);
	renderMesh->material.setVector("Light.La", Vector3(1.0f, 1.0f, 1.0f));
	renderMesh->material.setVector("Light.Ld", Vector3(1.0f, 1.0f, 1.0f));
	renderMesh->material.setVector("Material.Ka", Vector3(0.1f, 0.0f, 0.5f));
	renderMesh->material.setVector("Material.Kd", Vector3(0.25f, 0.0f, 1.0f));
	renderMesh->material.setFloat("levels", 3.0f);
	renderMesh->draw();
}