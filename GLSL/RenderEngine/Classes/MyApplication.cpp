#include "MyApplication.h"
#include "Time.h"

void MyApplication::Start()
{
	Shader shaderObj;
	shaderObj.compileShader(Shader::readShaderFile("RenderEngine/shaders/Phong-per-vertex.vert").c_str(), Shader::VERTEX);
	shaderObj.compileShader(Shader::readShaderFile("RenderEngine/shaders/Phong-per-vertex.frag").c_str(), Shader::FRAGMENT);
	shaderObj.linkProgram();
	sphere.material.shader = shaderObj;

	Mesh mesh;
	mesh.loadModel("RenderEngine/ObjFiles/sphere.obj");
	sphere.mesh = mesh;

	sphere.init();
	
	glEnable(GL_DEPTH_TEST);
}

void MyApplication::Update()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static float time{ 0.0f };
	time += Time::deltaTime * 6;

	Matrix4x4 model;
	model = Matrix4x4::scale(model, Vector3(6));
	model = Matrix4x4::rotate(model, radians(time * 10.0f), Vector3(1, 1, 0));
	model = Matrix4x4::translate(model, Vector3(0, 0, 0));

	Matrix4x4 view;
	view = Matrix4x4::lookAt(Vector3(0, 0, 10), Vector3(0, 0, 0), Vector3(0, 1, 0));
	Matrix4x4 ModelViewMatrix(view * model);
	Matrix4x4 ProjectionMatrix;
	ProjectionMatrix = Matrix4x4::ortho(-10, 10, -10, 10, -20, 20);

	static Vector3 lightPos(1.5f, 3.0f, 1.5f);
	lightPos.x = cos(time / 6) * 30;
	lightPos.z = sin(time / 6) * 30;

	sphere.material.shader.use();
	sphere.material.setMatrix("NormalMatrix", Matrix3x3(ModelViewMatrix));
	sphere.material.setMatrix("ModelViewMatrix", ModelViewMatrix);
	sphere.material.setMatrix("ProjectionMatrix", ProjectionMatrix);
	sphere.material.setMatrix("MVP", ProjectionMatrix * ModelViewMatrix);

	sphere.material.setVector("Light.LightPosition", Vector4(lightPos, 1));
	sphere.material.setVector("Light.La", Vector3(0.1, 0.1, 0.1));
	sphere.material.setVector("Material.Ka", Vector3(0.8, 0.3, 0.7));
	sphere.material.setVector("Light.Ld", Vector3(0.5, 0.5, 0.5));
	sphere.material.setVector("Material.Kd", Vector3(0.8, 0.3, 0.7));
	sphere.material.setVector("Light.Ls", Vector3(1, 1, 1));
	sphere.material.setVector("Material.Ks", Vector3(0.9f, 0.0f, 0.9f));

	sphere.material.setFloat("Material.Shininess", 2);
	sphere.draw();
}