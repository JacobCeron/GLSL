#pragma once

#include <string>
#include <array>
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
	void use();
	~Shader();
	void operator()(const char* name, float value);
	void operator()(const char* name, const glm::vec2& vector);
	void operator()(const char* name, const glm::vec3& vector);
	void operator()(const char* name, const glm::vec4& vector);
	void operator()(const char* name, const glm::mat4& matrix);
	static std::string readShaderFile(const std::string& fileName);
private:
	void error(unsigned int shader, ShaderType type = static_cast<ShaderType>(-1));
};
