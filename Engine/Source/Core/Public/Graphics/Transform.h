#pragma once

#include <FrostyCore.h>
#include <FrostyMath.h>
#include <Graphics/Window.h>
#include <Graphics/Camera.h>

#include <iostream>

class FROSTY_CORE_API Transform
{
public:
	Transform() : m_Position(Vector3f::Zero), m_Rotation(Vector3f::Zero), m_Scale(Vector3f::One) { }

	Matrix4f GetTransformationMatrix();
	Matrix4f GetProjectionMatrix();

	inline void Translate(float x, float y, float z) { this->Translate(Vector3f(x, y, z)); }
	inline void Translate(const Vector3f& position) { this->m_Position += position; }

	//void Rotate(const Vector3f& axis, float angle);
	//void Rotate(const Quaternion& rotation);

	inline void Rotate(float x, float y, float z) { this->Rotate(Vector3f(x, y, z)); }
	inline void Rotate(const Vector3f& rotation) { this->m_Rotation += rotation; }

	inline void Scale(float x, float y, float z) { this->Scale(Vector3f(x, y, z)); }
	inline void Scale(const Vector3f& scale) { this->m_Scale += scale; }

	inline const Vector3f& GetPosition() const { return this->m_Position; }
	inline void SetPosition(float x, float y, float z) { this->SetPosition(Vector3f(x, y, z)); }
	inline void SetPosition(const Vector3f& position) { this->m_Position = position; }

	//inline const Quaternion& GetRotation() const { return this->m_Rotation; }
	//inline void SetRotation(const Quaternion& rotation) { this->m_Rotation = rotation; }
	
	inline const Vector3f& GetRotation() const { return this->m_Rotation; }
	inline void SetRotation(float x, float y, float z) { this->SetRotation(Vector3f(x, y, z)); }
	inline void SetRotation(const Vector3f& rotation) { this->m_Rotation = rotation; }

	inline const Vector3f& GetScale() const { return this->m_Scale; }
	inline void SetScale(float x, float y, float z) { this->SetScale(Vector3f(x, y, z)); }
	inline void SetScale(const Vector3f& scale) { this->m_Scale = scale; }
private:
	Vector3f m_Position;
	Vector3f m_Rotation;
	Vector3f m_Scale;
};