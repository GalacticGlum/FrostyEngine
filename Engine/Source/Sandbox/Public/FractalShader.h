#pragma once

#include <FrostyCore.h>
#include <FrostyGraphics.h>
#include <Graphics/Material.h>

class FractalShader : public Shader
{
public:
	static FractalShader* GetInstance()
	{
		static FractalShader instance;
		return &instance;
	}

	void Update(const Matrix4f& mvpMatrix, const Material& material);
	Vector2f m_LightPosition;
private:
	inline FractalShader() : Shader("Assets/Shaders/lightTestVertex.shader", "Assets/Shaders/lightTestFragment.shader")
	{
		this->AddUniform("lightPosition");
		this->AddUniform("colour");
		this->AddUniform("mvpMatrix");
		this->AddUniform("transformationMatrix");
	}
};