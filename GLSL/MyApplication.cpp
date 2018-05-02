#include <glad\glad.h>

#include "MyApplication.h"

#include "RenderEngine/Classes/Time.h"
#include "RenderEngine/Classes/Camera.h"
#include "RenderEngine/Classes/MeshRenderer.h"
#include "RenderEngine/Classes/Transform.h"

MyApplication::MyApplication(int width, int height, const char * name)
	: CoreEngine(width, height, name)
{
}

MeshRenderer* meshRenderer;
Camera* cam;

float speed{ 6.0f };

void MyApplication::Start()
{
	Shader shaderObj;
	shaderObj.compileShader(Shader::readShaderFile("shaders/Interpolation.vert").c_str(), Shader::VERTEX);
	shaderObj.compileShader(Shader::readShaderFile("shaders/Interpolation.frag").c_str(), Shader::FRAGMENT);
	shaderObj.linkProgram();
	Mesh mesh;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/torus.obj");

	meshRenderer = mainObj.addComponent<MeshRenderer>();
	meshRenderer->mesh = mesh;
	meshRenderer->material.shader = shaderObj;

	camera.transform.Translate(Vector3(0.0f, 0.0f, 3.0f));
	camera.transform.localScale = Vector3(1.0f);
	cam = camera.addComponent<Camera>();
}

void MyApplication::Update()
{
	mainObj.transform.Rotate(Vector3(1.0f, 1.0f, 1.0f));
	if (Input::getKey(KeyCode::RightArrow))
		mainObj.transform.Translate(Vector3(Vector3::right * Time::deltaTime * speed));
	if (Input::getKey(KeyCode::LeftArrow))
		mainObj.transform.Translate(Vector3(-Vector3::right * Time::deltaTime * speed));
}