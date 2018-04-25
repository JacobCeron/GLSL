#include "MyApplication.h"
#include "Time.h"

void MyApplication::Start()
{
	Shader shaderObj;
	shaderObj.compileShader(Shader::readShaderFile("RenderEngine\\shaders\\test.vert").c_str(), Shader::VERTEX);
	shaderObj.compileShader(Shader::readShaderFile("RenderEngine\\shaders\\test.frag").c_str(), Shader::FRAGMENT);
	shaderObj.linkProgram();

	Mesh mesh;
	
	cube.material.shader = shaderObj;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/cube.obj");
	cube.mesh = mesh;
	cube.init();

	sphere.material.shader = shaderObj;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/sphere.obj");
	sphere.mesh = mesh;
	sphere.init();

	torus.material.shader = shaderObj;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/torus.obj");
	torus.mesh = mesh;
	torus.init();

	heart.material.shader = shaderObj;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/heart.obj");
	heart.mesh = mesh;
	heart.init();
	
	glEnable(GL_DEPTH_TEST);
}

void MyApplication::Update()
{
	glClearColor((166.0f / 255), (218.0f / 255), (257.0f / 255), 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static float time{ 0.0f };
	time += Time::deltaTime * 6;

	Matrix4x4 model;
	model = Matrix4x4::scale(model, Vector3(2));
	model = Matrix4x4::rotate(model, radians(time * 10.0f), Vector3(1, 1, 0));
	model = Matrix4x4::translate(model, Vector3(-7.5, 0, 0));
	Matrix4x4 view;
	view = Matrix4x4::lookAt(Vector3(0, 0, 10), Vector3(0, 0, 0), Vector3(0, 1, 0));
	Matrix4x4 ModelViewMatrix(view * model);
	Matrix4x4 ProjectionMatrix;
	ProjectionMatrix = Matrix4x4::ortho(-10, 10, -10, 10, -20, 20);

	cube.material.shader.use();
	cube.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	cube.draw();

	model = Matrix4x4();
	model = Matrix4x4::scale(model, Vector3(2));
	model = Matrix4x4::rotate(model, radians(time * 10.0f), Vector3(1, 1, 0));
	model = Matrix4x4::translate(model, Vector3(-2.5, 0, 0));
	ModelViewMatrix = view * model;

	sphere.material.shader.use();
	sphere.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	sphere.draw();

	model = Matrix4x4();
	model = Matrix4x4::scale(model, Vector3(2));
	model = Matrix4x4::rotate(model, radians(time * 10.0f), Vector3(1, 1, 0));
	model = Matrix4x4::translate(model, Vector3(2.5, 0, 0));
	ModelViewMatrix = view * model;

	torus.material.shader.use();
	torus.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	torus.draw();

	model = Matrix4x4();
	model = Matrix4x4::scale(model, Vector3(2));
	model = Matrix4x4::rotate(model, radians(time * 10.0f), Vector3(1, 1, 0));
	model = Matrix4x4::translate(model, Vector3(7.5, 0, 0));
	ModelViewMatrix = view * model;

	heart.material.shader.use();
	heart.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	heart.draw();
}