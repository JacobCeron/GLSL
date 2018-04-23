#include <glad\glad.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "MyApplication.h"
#include "Time.h"
#include "Mesh.h"

void MyApplication::Start()
{
	Shader shaderObj;
	shaderObj.compileShader(Shader::readShaderFile("src\\shaders\\simple.vert").c_str(), Shader::VERTEX);
	shaderObj.compileShader(Shader::readShaderFile("src\\shaders\\simple.frag").c_str(), Shader::FRAGMENT);
	shaderObj.linkProgram();

	object.material.shader = shaderObj;

	Mesh mesh;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/sphere.obj");
	object.mesh = mesh;
	object.init();

	glEnable(GL_DEPTH_TEST);
}

void MyApplication::Update()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static float time{ 0.0f };
	time += Time::deltaTime * 1.5;

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(0, 0, 0));
	model = glm::rotate(model, glm::radians(time * 10.0f), glm::vec3(1, 1, 0));
	glm::mat4 view;
	view = glm::lookAt(glm::vec3(0, 0, 6), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	glm::mat4 ModelViewMatrix(view * model);
	glm::mat4 ProjectionMatrix;
	ProjectionMatrix = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	static glm::vec3 lightPos(1.5f, 1.5f, 1.5f);
	//lightPos.x = cos(time) * 3;

	object.material.shader.use();
	object.material.setMatrix3x3("NormalMatrix", glm::mat3(glm::transpose(glm::inverse(ModelViewMatrix))));
	object.material.setMatrix4x4("ModelViewMatrix", ModelViewMatrix);
	object.material.setMatrix4x4("ProjectionMatrix", ProjectionMatrix);
	object.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	object.material.setVector4("Light.LightPosition", glm::vec4(lightPos, 1));
	object.material.setVector3("Light.La", glm::vec3(0.1, 0.1, 0.1));
	object.material.setVector3("Material.Ka", glm::vec3(1, 0.3, 0.5));
	object.material.setVector3("Light.Ld", glm::vec3(0.5, 0.5, 0.5));
	object.material.setVector3("Material.Kd", glm::vec3(1, 0.3, 0.5));
	object.material.setVector3("Light.Ls", glm::vec3(1, 1, 1));
	object.material.setVector3("Material.Ks", glm::vec3(1, 0.3, 0.5));
	object.material.setFloat("Material.Shininess", 32);

	object.draw();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}