#include <glad\glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Shader.h"

#include <iostream>

Shader::Shader()
{
}

void Shader::compileShader(const char* shaderSource, ShaderType type)
{
	m_shader[type] = glCreateShader(chooseType(type));
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

const unsigned int Shader::id() const
{
	return m_programID;
}

void Shader::operator()(const char* name, float value)
{
	glUniform1f(glGetUniformLocation(id(), name), value);
}

void Shader::operator()(unsigned int name, float value)
{
	glUniform1f(name, value);
}

void Shader::operator()(const char* name, const Vector2 & vector)
{
	glUniform2fv(glGetUniformLocation(id(), name), 1, &vector[0]);
}

void Shader::operator()(unsigned int name, const Vector2 & vector)
{
	glUniform2fv(name, 1, &vector[0]);
}

void Shader::operator()(const char* name, const Vector3 & vector)
{
	glUniform3fv(glGetUniformLocation(id(), name), 1, &vector[0]);
}

void Shader::operator()(unsigned int name, const Vector3 & vector)
{
	glUniform3fv(name, 1, &vector[0]);
}

void Shader::operator()(const char* name, const Vector4 & vector)
{
	glUniform4fv(glGetUniformLocation(id(), name), 1, &vector[0]);
}

void Shader::operator()(unsigned int name, const Vector4 & vector)
{
	glUniform4fv(name, 1, &vector[0]);
}

void Shader::operator()(const char* name, const Matrix3x3 & matrix)
{
	glUniformMatrix3fv(glGetUniformLocation(id(), name), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::operator()(unsigned int name, const Matrix3x3 & matrix)
{
	glUniformMatrix3fv(name, 1, GL_FALSE, &matrix[0][0]);
}

void Shader::operator()(const char* name, const Matrix4x4 & matrix)
{
	glUniformMatrix4fv(glGetUniformLocation(id(), name), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::operator()(unsigned int name, const Matrix4x4 & matrix)
{
	glUniformMatrix4fv(name, 1, GL_FALSE, &matrix[0][0]);
}

void Shader::operator()(const char* name, ShaderType type)
{
	int shaderType{ chooseType(type) };

	// NOT USING LOCATION OF SUBROUTINE
	// int locationOfSubroutine{ glGetSubroutineUniformLocation(id(), shaderType, nameSubroutine) };

	unsigned int indexSubroutine{ glGetSubroutineIndex(id(), shaderType, name) };
	glUniformSubroutinesuiv(shaderType, 1, &indexSubroutine);
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

int Shader::chooseType(ShaderType type)
{
	switch (type)
	{
	case Shader::VERTEX:
		return GL_VERTEX_SHADER;
		break;
	case Shader::TESS_CONTROL:
		return GL_TESS_CONTROL_SHADER;
		break;
	case Shader::TESS_EVALUATION:
		return GL_TESS_EVALUATION_SHADER;
		break;
	case Shader::GEOMETRY:
		return GL_GEOMETRY_SHADER;
		break;
	case Shader::FRAGMENT:
		return GL_FRAGMENT_SHADER;
		break;
	case Shader::COMPUTE:
		return GL_COMPUTE_SHADER;
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