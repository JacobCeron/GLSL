#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "MyApplication.h"
#include "Time.h"

void MyApplication::Start()
{
	Shader shaderObj;
	shaderObj.compileShader(Shader::readShaderFile("RenderEngine\\shaders\\test.vert").c_str(), Shader::VERTEX);
	shaderObj.compileShader(Shader::readShaderFile("RenderEngine\\shaders\\test.frag").c_str(), Shader::FRAGMENT);
	shaderObj.linkProgram();

	Mesh mesh;
	
	/*cube.material.shader = shaderObj;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/cube.obj");
	cube.mesh = mesh;
	cube.init();

	sphere.material.shader = shaderObj;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/sphere.obj");
	sphere.mesh = mesh;
	sphere.init();*/

	torus.material.shader = shaderObj;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/torus.obj");
	torus.mesh = mesh;
	torus.init();

	/*heart.material.shader = shaderObj;
	mesh.loadModel("C:/Users/UserHp/Desktop/Models/heart.obj");
	heart.mesh = mesh;
	heart.init();*/
	
	glEnable(GL_DEPTH_TEST);
}

void MyApplication::Update()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static float time{ 0.0f };
	time += Time::deltaTime * 6;

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(-4, 0, 0));
	model = glm::rotate(model, glm::radians(time * 10.0f), glm::vec3(1, 1, 0));
	glm::mat4 view;
	view = glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	glm::mat4 ModelViewMatrix(view * model);
	glm::mat4 ProjectionMatrix;
	ProjectionMatrix = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	static glm::vec3 lightPos(1.5f, 1.5f, 1.5f);
	lightPos.x = cos(time / 6) * 10;

	/*cube.material.shader.use();
	cube.material.setMatrix3x3("NormalMatrix", glm::mat3(glm::transpose(glm::inverse(ModelViewMatrix))));
	cube.material.setMatrix4x4("ModelViewMatrix", ModelViewMatrix);
	cube.material.setMatrix4x4("ProjectionMatrix", ProjectionMatrix);
	cube.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	cube.material.setVector4("Light.LightPosition", glm::vec4(lightPos, 1));
	cube.material.setVector3("Light.La", glm::vec3(0.1, 0.1, 0.1));
	cube.material.setVector3("Material.Ka", glm::vec3(0.2, 0.3, 0.5));
	cube.material.setVector3("Light.Ld", glm::vec3(0.5, 0.5, 0.5));
	cube.material.setVector3("Material.Kd", glm::vec3(0.2, 0.66, 0.96));
	cube.material.setVector3("Light.Ls", glm::vec3(1, 1, 1));
	cube.material.setVector3("Material.Ks", glm::vec3(1, 0.3, 0.5));
	cube.material.setFloat("Material.Shininess", 32);
	cube.draw();

	model = glm::mat4();
	model = glm::translate(model, glm::vec3(-1.5, 0, 0));
	model = glm::rotate(model, glm::radians(time * 10.0f), glm::vec3(1, 1, 0));
	ModelViewMatrix = view * model;

	sphere.material.shader.use();
	sphere.material.setMatrix3x3("NormalMatrix", glm::mat3(glm::transpose(glm::inverse(ModelViewMatrix))));
	sphere.material.setMatrix4x4("ModelViewMatrix", ModelViewMatrix);
	sphere.material.setMatrix4x4("ProjectionMatrix", ProjectionMatrix);
	sphere.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	sphere.material.setVector4("Light.LightPosition", glm::vec4(lightPos, 1));
	sphere.material.setVector3("Light.La", glm::vec3(0.1, 0.1, 0.1));
	sphere.material.setVector3("Material.Ka", glm::vec3(0.2, 0.3, 0.5));
	sphere.material.setVector3("Light.Ld", glm::vec3(0.5, 0.5, 0.5));
	sphere.material.setVector3("Material.Kd", glm::vec3(0.2, 0.66, 0.96));
	sphere.material.setVector3("Light.Ls", glm::vec3(1, 1, 1));
	sphere.material.setVector3("Material.Ks", glm::vec3(1, 0.3, 0.5));
	sphere.material.setFloat("Material.Shininess", 32);
	sphere.material.setVector3("eye", glm::vec3(0, 0, 10));
	sphere.draw();*/

	model = glm::mat4();
	//model = glm::translate(model, glm::vec3(1.5, 0, 0));
	model = glm::rotate(model, glm::radians(time * 10.0f), glm::vec3(1, 0, 0));
	//ModelViewMatrix = view * model;

	Matrix4x4 m;
	m = Matrix4x4::rotate(m, radians(time * 10.0f), Vector3(1, 0, 0));

	torus.material.shader.use();
	torus.material.setMatrix4x4("model", model);
	torus.material.setMatrix4x4("view", view);
	torus.material.setMatrix4x4("projection", ProjectionMatrix);
	/*torus.material.setMatrix3x3("NormalMatrix", glm::mat3(glm::transpose(glm::inverse(ModelViewMatrix))));
	torus.material.setMatrix4x4("ModelViewMatrix", ModelViewMatrix);
	torus.material.setMatrix4x4("ProjectionMatrix", ProjectionMatrix);
	torus.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	torus.material.setVector4("Light.LightPosition", glm::vec4(lightPos, 1));
	torus.material.setVector3("Light.La", glm::vec3(0.1, 0.1, 0.1));
	torus.material.setVector3("Material.Ka", glm::vec3(0.2, 0.3, 0.5));
	torus.material.setVector3("Light.Ld", glm::vec3(0.5, 0.5, 0.5));
	torus.material.setVector3("Material.Kd", glm::vec3(0.2, 0.66, 0.96));
	torus.material.setVector3("Light.Ls", glm::vec3(1, 1, 1));
	torus.material.setVector3("Material.Ks", glm::vec3(1, 0.3, 0.5));
	torus.material.setFloat("Material.Shininess", 32);*/
	torus.draw();

	/*model = glm::mat4();
	model = glm::translate(model, glm::vec3(4, 0, 0));
	model = glm::rotate(model, glm::radians(time * 10.0f), glm::vec3(1, 1, 0));
	ModelViewMatrix = view * model;

	heart.material.shader.use();
	heart.material.setMatrix3x3("NormalMatrix", glm::mat3(glm::transpose(glm::inverse(ModelViewMatrix))));
	heart.material.setMatrix4x4("ModelViewMatrix", ModelViewMatrix);
	heart.material.setMatrix4x4("ProjectionMatrix", ProjectionMatrix);
	heart.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	heart.material.setVector4("Light.LightPosition", glm::vec4(lightPos, 1));
	heart.material.setVector3("Light.La", glm::vec3(0.1, 0.1, 0.1));
	heart.material.setVector3("Material.Ka", glm::vec3(0.2, 0.3, 0.5));
	heart.material.setVector3("Light.Ld", glm::vec3(0.5, 0.5, 0.5));
	heart.material.setVector3("Material.Kd", glm::vec3(0.2, 0.66, 0.96));
	heart.material.setVector3("Light.Ls", glm::vec3(1, 1, 1));
	heart.material.setVector3("Material.Ks", glm::vec3(1, 0.3, 0.5));
	heart.material.setFloat("Material.Shininess", 32);
	heart.draw();*/

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}