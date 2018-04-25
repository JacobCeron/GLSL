#include "MyApplication.h"
#include "Time.h"

void MyApplication::Start()
{
	Shader shaderObj;
	shaderObj.compileShader(Shader::readShaderFile("RenderEngine\\shaders\\Gouraud.vert").c_str(), Shader::VERTEX);
	shaderObj.compileShader(Shader::readShaderFile("RenderEngine\\shaders\\Gouraud.frag").c_str(), Shader::FRAGMENT);
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
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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

	static Vector3 lightPos(1.5f, 3.0f, 1.5f);
	lightPos.x = cos(time / 6) * 30;
	lightPos.z = sin(time / 6) * 30;

	cube.material.shader.use();
	cube.material.setMatrix3x3("NormalMatrix", Matrix3x3(ModelViewMatrix));
	cube.material.setMatrix4x4("ModelViewMatrix", ModelViewMatrix);
	cube.material.setMatrix4x4("ProjectionMatrix", ProjectionMatrix);
	cube.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	cube.material.setVector4("Light.LightPosition", Vector4(lightPos, 1));
	cube.material.setVector3("Light.La", Vector3(0.1, 0.1, 0.1));
	cube.material.setVector3("Material.Ka", Vector3(0.2, 0.3, 0.5));
	cube.material.setVector3("Light.Ld", Vector3(0.5, 0.5, 0.5));
	cube.material.setVector3("Material.Kd", Vector3(0.2, 0.66, 0.96));
	cube.material.setVector3("Light.Ls", Vector3(1, 1, 1));
	cube.material.setVector3("Material.Ks", Vector3(1, 0.3, 0.5));
	cube.material.setFloat("Material.Shininess", 32);
	cube.draw();

	model = Matrix4x4();
	model = Matrix4x4::scale(model, Vector3(2));
	model = Matrix4x4::rotate(model, radians(time * 10.0f), Vector3(1, 1, 0));
	model = Matrix4x4::translate(model, Vector3(-2.5, 0, 0));
	ModelViewMatrix = view * model;

	sphere.material.shader.use();
	sphere.material.setMatrix3x3("NormalMatrix", Matrix3x3(ModelViewMatrix));
	sphere.material.setMatrix4x4("ModelViewMatrix", ModelViewMatrix);
	sphere.material.setMatrix4x4("ProjectionMatrix", ProjectionMatrix);
	sphere.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	sphere.material.setVector4("Light.LightPosition", Vector4(lightPos, 1));
	sphere.material.setVector3("Light.La", Vector3(0.1, 0.1, 0.1));
	sphere.material.setVector3("Material.Ka", Vector3(0.2, 0.3, 0.5));
	sphere.material.setVector3("Light.Ld", Vector3(0.5, 0.5, 0.5));
	sphere.material.setVector3("Material.Kd", Vector3(0.2, 0.66, 0.96));
	sphere.material.setVector3("Light.Ls", Vector3(1, 1, 1));
	sphere.material.setVector3("Material.Ks", Vector3(1, 0.3, 0.5));
	sphere.material.setFloat("Material.Shininess", 32);
	sphere.draw();

	model = Matrix4x4();
	model = Matrix4x4::scale(model, Vector3(2));
	model = Matrix4x4::rotate(model, radians(time * 10.0f), Vector3(1, 1, 0));
	model = Matrix4x4::translate(model, Vector3(2.5, 0, 0));
	ModelViewMatrix = view * model;

	torus.material.shader.use();
	torus.material.setMatrix3x3("NormalMatrix", Matrix3x3(ModelViewMatrix));
	torus.material.setMatrix4x4("ModelViewMatrix", ModelViewMatrix);
	torus.material.setMatrix4x4("ProjectionMatrix", ProjectionMatrix);
	torus.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	torus.material.setVector4("Light.LightPosition", Vector4(lightPos, 1));
	torus.material.setVector3("Light.La", Vector3(0.1, 0.1, 0.1));
	torus.material.setVector3("Material.Ka", Vector3(0.2, 0.3, 0.5));
	torus.material.setVector3("Light.Ld", Vector3(0.5, 0.5, 0.5));
	torus.material.setVector3("Material.Kd", Vector3(0.2, 0.66, 0.96));
	torus.material.setVector3("Light.Ls", Vector3(1, 1, 1));
	torus.material.setVector3("Material.Ks", Vector3(1, 0.3, 0.5));
	torus.material.setFloat("Material.Shininess", 32);
	torus.draw();

	model = Matrix4x4();
	model = Matrix4x4::scale(model, Vector3(2));
	model = Matrix4x4::rotate(model, radians(time * 10.0f), Vector3(1, 1, 0));
	model = Matrix4x4::translate(model, Vector3(7.5, 0, 0));
	ModelViewMatrix = view * model;

	heart.material.shader.use();
	heart.material.setMatrix3x3("NormalMatrix", Matrix3x3(ModelViewMatrix));
	heart.material.setMatrix4x4("ModelViewMatrix", ModelViewMatrix);
	heart.material.setMatrix4x4("ProjectionMatrix", ProjectionMatrix);
	heart.material.setMatrix4x4("MVP", ProjectionMatrix * ModelViewMatrix);
	heart.material.setVector4("Light.LightPosition", Vector4(lightPos, 1));
	heart.material.setVector3("Light.La", Vector3(0.1, 0.1, 0.1));
	heart.material.setVector3("Material.Ka", Vector3(0.2, 0.3, 0.5));
	heart.material.setVector3("Light.Ld", Vector3(0.5, 0.5, 0.5));
	heart.material.setVector3("Material.Kd", Vector3(0.2, 0.66, 0.96));
	heart.material.setVector3("Light.Ls", Vector3(1, 1, 1));
	heart.material.setVector3("Material.Ks", Vector3(1, 0.3, 0.5));
	heart.material.setFloat("Material.Shininess", 32);
	heart.draw();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}