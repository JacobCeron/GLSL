#include "MyApplication.h"

#include "RenderEngine/Classes/Time.h"
#include "RenderEngine/Classes/Camera.h"
#include "RenderEngine/Classes/MeshRenderer.h"
#include "RenderEngine/Classes/Transform.h"
#include "RenderEngine/Classes/DirectionalLight.h"

MyApplication::MyApplication(int width, int height, const char * name)
	: CoreEngine(width, height, name)
{
}

MeshRenderer* meshRenderer;
Camera* cam;
DirectionalLight* dirL;

float speed{ 6.0f };
float time{ 0.0f };

void MyApplication::Start()
{
	Shader shaderObj;
	shaderObj.compileShader(Shader::readShaderFile("shaders/Cel.vert").c_str(), Shader::VERTEX);
	shaderObj.compileShader(Shader::readShaderFile("shaders/Cel.frag").c_str(), Shader::FRAGMENT);
	shaderObj.linkProgram();
	Mesh mesh;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/torus.obj");

	meshRenderer = mainObj.addComponent<MeshRenderer>();
	meshRenderer->mesh = mesh;
	meshRenderer->material.shader = shaderObj;

	camera.transform.Translate(Vector3(0.0f, 0.0f, 3.0f));
	camera.transform.localScale = Vector3(1.0f);
	cam = camera.addComponent<Camera>();

	dirLight.transform.Translate(Vector3(6.0f, 6.0f, 6.0f));
	dirLight.transform.Rotate(Vector3(3.0f, -1.0f, 0.0f));
	dirL = dirLight.addComponent<DirectionalLight>();
	dirL->setColor(Vector4(0.0f, 1.0f, 0.0f, 1.0f));

	dirLight2.transform.Translate(Vector3(-6.0f, 6.0f, 6.0f));
	dirLight2.transform.Rotate(Vector3(-50.0f, 30.0f, 0.0f));
	dirLight2.addComponent<DirectionalLight>();

	mainObj.transform.localScale = Vector3(2.0f);
}

void MyApplication::Update()
{
	time += Time::deltaTime;

	mainObj.transform.Rotate(Vector3(0.5f, 0.5f, 0.5f));
	if (Input::getKey(KeyCode::D))
		mainObj.transform.Translate(Vector3(Vector3::right * Time::deltaTime * speed));
	if (Input::getKey(KeyCode::A))
		mainObj.transform.Translate(Vector3(-Vector3::right * Time::deltaTime * speed));

	if (Input::getKey(KeyCode::W))
		dirLight.transform.Rotate(Vector3(Vector3::forward * Time::deltaTime * 60.0f));
	if (Input::getKey(KeyCode::S))
		dirLight.transform.Rotate(Vector3(-Vector3::forward * Time::deltaTime * 60.0f));

	meshRenderer->material.setFloat("levels", 3.0f);
}