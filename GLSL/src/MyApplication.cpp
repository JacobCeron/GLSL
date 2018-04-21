#include <glad\glad.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <iostream>

#include "MyApplication.h"
#include "Time.h"
#include "Mesh.h"

void MyApplication::Start()
{
	Shader shaderCube;
	shaderCube.compileShader(Shader::readShaderFile("src\\shaders\\simple.vert").c_str(), Shader::VERTEX);
	shaderCube.compileShader(Shader::readShaderFile("src\\shaders\\simple.frag").c_str(), Shader::FRAGMENT);
	shaderCube.linkProgram();

	cube.material.shader = shaderCube;

	Mesh mesh;
	mesh.loadModel("C:\\Users\\UserHp\\Desktop\\snowMan.obj");

	cube.mesh = mesh;
	cube.init();

	glEnable(GL_DEPTH_TEST);
}

void MyApplication::Update()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static float time{ 0.0f };
	time += Time::deltaTime * 6.0f;

	glm::mat4 model;
	model = glm::rotate(model, glm::radians(time * 10.0f), glm::vec3(0, 1, 0));
	glm::mat4 view;
	view = glm::lookAt(glm::vec3(0, 0, 6), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	cube.material.shader.use();
	cube.material.setMatrix4x4("transforms.model", model);
	cube.material.setMatrix4x4("transforms.view", view);
	cube.material.setMatrix4x4("transforms.projection", projection);
	cube.draw();
}