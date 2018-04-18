#include <glad\glad.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "MyApplication.h"
#include "Time.h"
#include "Mesh.h"

void MyApplication::Start()
{
	Shader shaderCube;
	shaderCube.compileShader(Shader::readShaderFile("src\\shaders\\cube.vert").c_str(), Shader::VERTEX);
	shaderCube.compileShader(Shader::readShaderFile("src\\shaders\\cube.frag").c_str(), Shader::FRAGMENT);
	shaderCube.linkProgram();

	cubeMat.shader = shaderCube;

	Shader shaderLight;
	shaderLight.compileShader(Shader::readShaderFile("src\\shaders\\light.vert").c_str(), Shader::VERTEX);
	shaderLight.compileShader(Shader::readShaderFile("src\\shaders\\light.frag").c_str(), Shader::FRAGMENT);
	shaderLight.linkProgram();

	lightMat.shader = shaderLight;

	Mesh mesh;
	mesh.loadModel("src\\models\\cube.obj");

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	size_t iPosSize{ sizeof(mesh.indexPosition[0]) * mesh.indexPosition.size() };
	size_t iNorSize{ sizeof(mesh.indexNormal[0]) * mesh.indexNormal.size() };

	eB.init(iPosSize + iNorSize, nullptr);
	eB.updateData(0, iPosSize, &mesh.indexPosition[0]);
	eB.updateData(iPosSize, iNorSize, &mesh.indexNormal[0]);

	size_t posSize{ sizeof(mesh.position[0]) * mesh.position.size() };
	size_t norSize{ sizeof(mesh.normal[0]) * mesh.normal.size() };

	vB.init(posSize + norSize, nullptr);
	vB.updateData(0, posSize, &mesh.position[0]);
	vB.updateData(posSize, norSize, &mesh.normal[0]);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(1);

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

	cubeMat.shader.use();
	cubeMat.setMatrix4x4("transforms.model", model);
	cubeMat.setMatrix4x4("transforms.view", view);
	cubeMat.setMatrix4x4("transforms.projection", projection);
	cubeMat.setVector3("color", glm::vec3(sin(time / 6.0f * 2.0f), sin(time / 6.0f) + 0.15, cos(time / 6.0f) + 0.25));
	cubeMat.setVector3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	static glm::vec3 lightPos(1.5f, 1.5f, 1.5f);
	cubeMat.setVector3("lightPos", lightPos);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	model = glm::mat4();
	model = glm::translate(model, lightPos);
	model = glm::scale(model, glm::vec3(0.25f));

	lightMat.shader.use();
	lightMat.setMatrix4x4("transforms.model", model);
	lightMat.setMatrix4x4("transforms.view", view);
	lightMat.setMatrix4x4("transforms.projection", projection);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}