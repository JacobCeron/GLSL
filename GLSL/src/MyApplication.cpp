#include <glad\glad.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <iostream>

#include "MyApplication.h"
#include "Time.h"
#include "Vector.h"

void MyApplication::Start()
{
	Vector<float, 4> a{ 1, 2, 3, 4 };
	Vector<float, 4> b{ 5, 6, 7, 8 };

	Vector<float, 4> c(a);
	for (const auto& _c : c)
		std::cout << _c << " ";
	std::cout << std::endl;

	std::cout << Vector<int, 4>::magnitud(c) << std::endl;

	shaderCube.compileShader(Shader::readShaderFile("src\\shaders\\cube.vert").c_str(), Shader::VERTEX);
	shaderCube.compileShader(Shader::readShaderFile("src\\shaders\\cube.frag").c_str(), Shader::FRAGMENT);
	shaderCube.linkProgram();

	shaderLight.compileShader(Shader::readShaderFile("src\\shaders\\light.vert").c_str(), Shader::VERTEX);
	shaderLight.compileShader(Shader::readShaderFile("src\\shaders\\light.frag").c_str(), Shader::FRAGMENT);
	shaderLight.linkProgram();

	Vector<float, 3> pos[]
	{
		Vector<float, 3>{-0.5f, -0.5f, 0.5f},
		Vector<float, 3>{0.5f, -0.5f, 0.5f},
		Vector<float, 3>{-0.5f, 0.5f, 0.5f},
		Vector<float, 3>{0.5f, 0.5f, 0.5f},
		Vector<float, 3>{-0.5f, 0.5f, -0.5f},
		Vector<float, 3>{0.5f, 0.5f, -0.5f},
		Vector<float, 3>{-0.5f, -0.5f, -0.5f},
		Vector<float, 3>{0.5f, -0.5f, -0.5f}
	};

	Vector<float, 3> nor[]
	{
		Vector<float, 3>{0.0f, 0.0f, 1.0f},
		Vector<float, 3>{0.0f, 1.0f, 0.0f},
		Vector<float, 3>{0.0f, 0.0f, -1.0f},
		Vector<float, 3>{0.0f, -1.0f, 0.0f},
		Vector<float, 3>{1.0f, 0.0f, 0.0f},
		Vector<float, 3>{-1.0f, 0.0f, 0.0f}
	};

	Vector<unsigned int, 3> indP[]
	{
		Vector<unsigned int, 3>{0, 1, 2},
		Vector<unsigned int, 3>{2, 1, 3},
		Vector<unsigned int, 3>{2, 3, 4},
		Vector<unsigned int, 3>{4, 3, 5},
		Vector<unsigned int, 3>{4, 5, 6},
		Vector<unsigned int, 3>{6, 5, 7},
		Vector<unsigned int, 3>{6, 7, 0},
		Vector<unsigned int, 3>{0, 7, 1},
		Vector<unsigned int, 3>{1, 7, 3},
		Vector<unsigned int, 3>{3, 7, 5},
		Vector<unsigned int, 3>{6, 0, 4},
		Vector<unsigned int, 3>{4, 0, 2},
	};

	Vector<unsigned int, 3> indN[]
	{
		Vector<unsigned int, 3>{0, 0, 0},
		Vector<unsigned int, 3>{0, 0, 0},
		Vector<unsigned int, 3>{1, 1, 1},
		Vector<unsigned int, 3>{1, 1, 1},
		Vector<unsigned int, 3>{2, 2, 2},
		Vector<unsigned int, 3>{2, 2, 2},
		Vector<unsigned int, 3>{3, 3, 3},
		Vector<unsigned int, 3>{3, 3, 3},
		Vector<unsigned int, 3>{4, 4, 4},
		Vector<unsigned int, 3>{4, 4, 4},
		Vector<unsigned int, 3>{5, 5, 5},
		Vector<unsigned int, 3>{5, 5, 5},
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	eB.init(sizeof(indP) + sizeof(indN), nullptr);
	eB.updateData(0, sizeof(indP), indP);
	eB.updateData(sizeof(indP), sizeof(indN), indN);

	vB.init(sizeof(pos) + sizeof(nor), nullptr);
	vB.updateData(0, sizeof(pos), pos);
	vB.updateData(sizeof(pos), sizeof(nor), nor);

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

	shaderCube.use();
	shaderCube("transforms.model", model);
	shaderCube("transforms.view", view);
	shaderCube("transforms.projection", projection);

	shaderCube("color", glm::vec3(sin(time / 6.0f * 2.0f), sin(time / 6.0f) + 0.15, cos(time / 6.0f) + 0.25));
	shaderCube("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));

	static glm::vec3 lightPos (1.5f, 1.5f, 1.5f);
	shaderCube("lightPos", lightPos);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	model = glm::mat4();
	model = glm::translate(model, lightPos);
	model = glm::scale(model, glm::vec3(0.25f));

	shaderLight.use();
	shaderLight("transforms.model", model);
	shaderLight("transforms.view", view);
	shaderLight("transforms.projection", projection);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}