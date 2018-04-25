#include <glad\glad.h>

#include "MyApplication.h"
#include "RenderEngine/Classes/Time.h"

void MyApplication::Start()
{
	Shader shaderObj;
	shaderObj.compileShader(Shader::readShaderFile("shaders/Phong-per-vertex.vert").c_str(), Shader::VERTEX);
	shaderObj.compileShader(Shader::readShaderFile("shaders/Phong-per-vertex.frag").c_str(), Shader::FRAGMENT);
	shaderObj.linkProgram();
	sphere.material.shader = shaderObj;

	Mesh mesh;
	mesh.loadModel("ObjFiles/sphere.obj");
	sphere.mesh = mesh;

	sphere.init();
	
	glEnable(GL_DEPTH_TEST);
}

void MyApplication::Update()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static float time{ 0.0f };
	time += Time::deltaTime * 6.0f;

	Matrix4x4 model;
	model = Matrix4x4::scale(model, Vector3(6.0f));
	model = Matrix4x4::rotate(model, radians(time * 6), Vector3(1.0f, 1.0f, 0.0f));
	model = Matrix4x4::translate(model, Vector3(0.0f, 0.0f, 0.0f));

	Matrix4x4 view;
	view = Matrix4x4::lookAt(Vector3(0.0f, 0.0f, 10.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f));
	Matrix4x4 ModelViewMatrix(view * model);
	Matrix4x4 ProjectionMatrix;
	ProjectionMatrix = Matrix4x4::ortho(-10.0f, 10.0f, -10.0f, 10.0f, -20.0f, 20.0f);

	static Vector3 lightPos(1.5f, 3.0f, 1.5f);

	sphere.material.shader.use();
	sphere.material.setMatrix(1, Matrix3x3(ModelViewMatrix));
	sphere.material.setMatrix(2, ModelViewMatrix);
	sphere.material.setMatrix(3, ProjectionMatrix * ModelViewMatrix);

	sphere.material.setVector("Light.LightPosition", Vector4(lightPos, 1));
	sphere.material.setVector("Light.La", Vector3(0.25f, 0.25f, 0.0f));
	sphere.material.setVector("Material.Ka", Vector3(0.5f, 1.0f, 0.0f));
	sphere.material.setVector("Light.Ld", Vector3(0.5f, 0.5f, 0.0f));
	sphere.material.setVector("Material.Kd", Vector3(0.5f, 1.0f, 0.0f));
	sphere.material.setVector("Light.Ls", Vector3(1.0f, 1.0f, 0.0f));
	sphere.material.setVector("Material.Ks", Vector3(0.5f, 1.0f, 0.0f));

	sphere.material.setFloat("Material.Shininess", 1.0f);

	sphere.material.setSubroutine("phongModel", Shader::VERTEX);

	sphere.draw();

	glProvokingVertex(GL_LAST_VERTEX_CONVENTION);
}