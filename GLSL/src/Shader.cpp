#include <glad\glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Shader.h"

Shader::Shader()
{
}

void Shader::compileShader(const char* shaderSource, ShaderType type)
{
	switch (type)
	{
	case VERTEX:
		m_shader[type] = glCreateShader(GL_VERTEX_SHADER);
		break;
	case TESS_CONTROL:
		m_shader[type] = glCreateShader(GL_TESS_CONTROL_SHADER);
		break;
	case TESS_EVALUATION:
		m_shader[type] = glCreateShader(GL_TESS_EVALUATION_SHADER);
		break;
	case GEOMETRY:
		m_shader[type] = glCreateShader(GL_GEOMETRY_SHADER);
		break;
	case FRAGMENT:
		m_shader[type] = glCreateShader(GL_FRAGMENT_SHADER);
		break;
	case COMPUTE:
		m_shader[type] = glCreateShader(GL_COMPUTE_SHADER);
		break;
	}
	glShaderSource(m_shader[type], 1, &shaderSource, nullptr);
	glCompileShader(m_shader[type]);
	error(m_shader[type], type);
}

void Shader::linkProgram()
{
	m_programID = glCreateProgram();
	for (const auto& shader : m_shader)
		glAttachShader(m_programID, shader);
	glLinkProgram(m_programID);
	error(m_programID);
	for (const auto& shader : m_shader)
		glDeleteShader(shader);
}

void Shader::use()
{
	glUseProgram(m_programID);
}

void Shader::operator()(const char* name, float value)
{
	glUniform1f(glGetUniformLocation(m_programID, name), value);
}

void Shader::operator()(const char* name, const glm::vec2 & vector)
{
	glUniform2fv(glGetUniformLocation(m_programID, name), 1, &vector[0]);
}

void Shader::operator()(const char* name, const glm::vec3 & vector)
{
	glUniform3fv(glGetUniformLocation(m_programID, name), 1, &vector[0]);
}

void Shader::operator()(const char* name, const glm::vec4 & vector)
{
	glUniform4fv(glGetUniformLocation(m_programID, name), 1, &vector[0]);
}

void Shader::operator()(const char* name, const glm::mat3 & matrix)
{
	glUniformMatrix3fv(glGetUniformLocation(m_programID, name), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::operator()(const char* name, const glm::mat4 & matrix)
{
	glUniformMatrix4fv(glGetUniformLocation(m_programID, name), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::error(unsigned int shader, ShaderType type)
{
	int success;
	char infoLog[512];
	switch (type)
	{
	case VERTEX:
	case TESS_CONTROL:
	case TESS_EVALUATION:
	case GEOMETRY:
	case COMPUTE:
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			std::cout << "SHADER_" << type << "_ERROR:\n" << infoLog << std::endl;
		}
		break;
	default:
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 512, nullptr, infoLog);
			std::cout << "SHADER_PROGRAM_ERROR:\n" << infoLog << std::endl;
		}
		break;
	}
}

std::string Shader::readShaderFile(const std::string& fileName)
{
	std::ifstream file(fileName);
	if (!file)
		return nullptr;
	std::stringstream stream;
	stream << file.rdbuf();
	return stream.str();
}

Shader::~Shader()
{
}