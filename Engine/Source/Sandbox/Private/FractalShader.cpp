#include <FractalShader.h>

void FractalShader::Update(const Matrix4f& mvpMatrix, const Material& material)
{
	Matrix4f translation = Matrix4f::Scale(Vector3f(800, 600, 0));

	this->SetUniform("colour", material.DiffuseColour);
	this->SetUniform("lightPosition", this->m_LightPosition);
	this->SetUniform("mvpMatrix", mvpMatrix * translation);
	this->SetUniform("transformationMatrix", translation);
}