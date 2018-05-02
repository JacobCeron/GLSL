#pragma once

#include <string>
#include <array>

#include "Maths.h"

#include <glm\glm.hpp>

class Shader
{
public:
	enum ShaderType
	{
		VERTEX,
		TESS_CONTROL,
		TESS_EVALUATION,
		GEOMETRY,
		FRAGMENT,
		COMPUTE
	};
private:
	unsigned int m_programID;
	std::array<unsigned int, 6> m_shader;

public:
	Shader();
	void compileShader(const char* shadeSource, ShaderType type);
	void linkProgram();
//	void use(); // Inside Renderer Engine
	const unsigned int id() const;
	~Shader();

	void operator()(const char* name, float value);
	void operator()(unsigned int name, float value);
	void operator()(const char* name, const Vector2& vector);
	void operator()(unsigned int name, const Vector2& vector);
	void operator()(const char* name, const Vector3& vector);
	void operator()(unsigned int name, const Vector3& vector);
	void operator()(const char* name, const Vector4& vector);
	void operator()(unsigned int name, const Vector4& vector);
	void operator()(const char* name, const Matrix3x3& matrix);
	void operator()(unsigned int name, const Matrix3x3& matrix);
	void operator()(const char* name, const Matrix4x4& matrix);
	void operator()(unsigned int name, const Matrix4x4& matrix);
	void operator()(const char* name, ShaderType type);
	//void operator()(const char* nameSubroutine, const char* name, ShaderType type);

	void operator()(const char* name, const glm::mat4& matrix);

	static std::string readShaderFile(const std::string& fileName);
private:
	void error(unsigned int shader, ShaderType type = static_cast<ShaderType>(-1));
	int chooseType(ShaderType type);
	void use();

	friend class RendererEngine;
};
