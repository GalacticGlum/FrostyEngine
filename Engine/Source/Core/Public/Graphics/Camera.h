#pragma once

#include <iostream>

#include <FrostyCore.h>
#include <FrostyMath.h>
#include <FrostyInput.h>

class FROSTY_CORE_API Camera
{
public:
	inline Camera() : Camera(Vector3f::Zero) {}
	inline Camera(const Vector3f& position) : Camera(position, Vector3f::Forward, Vector3f::Up) {}
	inline Camera(const Vector3f& position, const Vector3f& forward, const Vector3f& up)  : m_Position(position), m_Forward(forward), m_Up(up) {}

	void Update(float deltaTime);

	void Move(const Vector3f& direction, float speed);
	inline void Rotate(float angleX, float angleY) { this->Rotate(Vector2f(angleX, angleY)); }
	void Rotate(const Vector2f& angles);

	inline const Vector3f& GetPosition() const { return this->m_Position; }
	inline void SetPosition(const Vector3f& position) { this->m_Position = position; }

	inline const Vector3f& GetForward() const { return this->m_Forward; }
	inline void SetForward(const Vector3f& forward) { this->m_Forward = forward; }

	inline const Vector3f& GetUp() const { return this->m_Up; }
	inline void SetUp(const Vector3f& up) { this->m_Up = up; }

	inline const Vector3f GetLeft() const { return this->m_Forward.Cross(this->m_Up).Normalized(); }
	inline const Vector3f GetRight() const { return this->m_Up.Cross(this->m_Forward).Normalized(); }

	const Matrix4f GetViewProjection() const;
private:
	const float Z_NEAR = 0.1f;
	const float Z_FAR = 1000.0f;
	const float WIDTH = 800.0f;
	const float HEIGHT = 600.0f;
	const float FOV = 70.0f;

	Vector3f m_Position;
	Vector3f m_Forward;
	Vector3f m_Up;
};