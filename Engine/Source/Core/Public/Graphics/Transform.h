#pragma once

#include <FrostyCore.h>
#include <FrostyMath.h>

#include <iostream>

class Camera;
class FROSTY_CORE_API Transform
{
public:
	Transform();
	~Transform();

	Matrix4f GetTransformation();
	Matrix4f GetProjectedTransformation();

	void Update();

	inline const Vector3f& GetPosition() const { return this->m_Position; }
	inline void SetPosition(float x, float y, float z) { this->SetPosition(Vector3f(x, y, z)); }
	inline void SetPosition(const Vector3f& position) { this->m_Position = position; }

	inline const Vector3f& GetRotation() const { return this->m_Rotation; }
	inline void SetRotation(float x, float y, float z) { this->SetRotation(Vector3f(x, y, z)); }
	inline void SetRotation(const Vector3f& rotation) { this->m_Rotation = rotation; }

	inline const Vector3f& GetScale() const { return this->m_Scale; }
	inline void SetScale(float x, float y, float z) { this->SetScale(Vector3f(x, y, z)); }
	inline void SetScale(const Vector3f& scale) { this->m_Scale = scale; }
private:
	const float Z_NEAR = 0.1f;
	const float Z_FAR = 1000.0f;
	const float WIDTH = 800.0f;
	const float HEIGHT = 600.0f;
	const float FOV = 70.0f;

	Vector3f m_Position;
	Vector3f m_Rotation;
	Vector3f m_Scale;

	Camera* m_Camera;
};