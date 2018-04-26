#include <glad\glad.h>

#include "MyApplication.h"
#include "RenderEngine/Classes/Time.h"

void MyApplication::Start()
{
	Shader shaderObj;
	shaderObj.compileShader(Shader::readShaderFile("shaders/Phong.vert").c_str(), Shader::VERTEX);
	shaderObj.compileShader(Shader::readShaderFile("shaders/Phong.frag").c_str(), Shader::FRAGMENT);
	shaderObj.linkProgram();
	renderMesh.material.shader = shaderObj;

	Mesh mesh;
	mesh.loadModel("ObjFiles/sphere.obj");
	renderMesh.mesh = mesh;

	renderMesh.init();
	
	glEnable(GL_DEPTH_TEST);
}

void MyApplication::Update()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static float time{ 0.5f };
	time += Time::deltaTime * 6.0f;

	Matrix4x4 ModelMatrix;
	ModelMatrix = Matrix4x4::scale(ModelMatrix, Vector3(6.0f));
	ModelMatrix = Matrix4x4::rotate(ModelMatrix, radians(time) * 6.0f, Vector3(0.0f, 1.0f, 1.0f));
	ModelMatrix = Matrix4x4::translate(ModelMatrix, Vector3(0.0f, 0.0f, 0.0f));

	Matrix4x4 ViewMatrix;
	ViewMatrix = Matrix4x4::lookAt(Vector3(0.0f, 0.0f, 10.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f));
	Matrix4x4 ProjectionMatrix;
	ProjectionMatrix = Matrix4x4::ortho(-10.0f, 10.0f, -10.0f, 10.0f, -20.0f, 20.0f);

	static Vector3 LightPosition(1.5f, 6.0f, 1.5f);
	LightPosition.x = cos(time / 3.0f) * 10.0f;
	LightPosition.z = sin(time / 3.0f) * 10.0f;

	renderMesh.material.shader.use();
	// Vertex Shader
	renderMesh.material.setMatrix(1, ModelMatrix);
	renderMesh.material.setMatrix(2, ViewMatrix);
	renderMesh.material.setMatrix(3, ProjectionMatrix);
	// Fragment Shader
	renderMesh.material.setVector("EyePosition", Vector3(0.0f, 0.0f, 10.0f));
	// Light
	renderMesh.material.setVector("Light.Position", LightPosition);
	renderMesh.material.setVector("Light.La", Vector3(0.2f, 0.2f, 0.2f));
	renderMesh.material.setVector("Light.Ld", Vector3(0.5f, 0.5f, 0.5f));
	renderMesh.material.setVector("Light.Ls", Vector3(1.0f, 0.5f, 0.31f));
	// Material
	renderMesh.material.setVector("Material.Ka", Vector3(1.0f, 0.5f, 0.31f));
	renderMesh.material.setVector("Material.Kd", Vector3(1.0f, 0.5f, 0.31f));
	renderMesh.material.setVector("Material.Ks", Vector3(0.5f, 0.5f, 0.5f));
	renderMesh.material.setFloat("Material.Shininess", 128.0f);
	renderMesh.draw();
}