#pragma once

#include <map>
#include <vector>

#include <string>
#include <iostream>
#include <GL/glew.h>

#include <FrostyCore.h>
#include <FrostyMath.h>
#include <System/File.h>

class FROSTY_CORE_API Shader
{
public:
	Shader(std::string vertexFilePath, std::string fragmentFilePath);
	~Shader();

	inline void Start() { glUseProgram(this->m_ShaderProgram); }
	inline void Stop() { glUseProgram(0); }

	void AddUniform(const std::string& uniformName);
	inline void SetUniformi(const std::string& uniformName, int value) { glUniform1i(this->m_Uniforms.at(uniformName), value); }
	inline void SetUniformf(const std::string& uniformName, float value) { glUniform1f(this->m_Uniforms.at(uniformName), value); }
	inline void Setuniform(const std::string& uniformName, bool value) { glUniform1i(this->m_Uniforms.at(uniformName), value ? 1 : 0); }
	inline void SetUniform(const std::string& uniformName, const Vector2f& value) { glUniform2f(this->m_Uniforms.at(uniformName), value.X, value.Y); }
	inline void SetUniform(const std::string& uniformName, const Vector3f& value) { glUniform3f(this->m_Uniforms.at(uniformName), value.X, value.Y, value.Z); }
	inline void SetUniform(const std::string& uniformName, const Vector4f& value) { glUniform4f(this->m_Uniforms.at(uniformName), value.X, value.Y, value.Z, value.W); }
	inline void SetUniform(const std::string& uniformName, const Matrix4f& value) { glUniformMatrix4fv(this->m_Uniforms.at(uniformName), 1, GL_TRUE, value.Elements); }

	inline void SetAttributeLocation(const std::string& attributeName, GLuint attributeLocation) { glBindAttribLocation(this->m_ShaderProgram, attributeLocation, attributeName.c_str()); }

private:
	int m_ShaderProgram;

	std::vector<GLuint> m_Shaders;
	std::map<std::string, GLuint> m_Uniforms;

	void AddShader(std::string filePath, GLenum shaderType);
	void LinkShaders();
};