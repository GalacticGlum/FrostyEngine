#pragma once

#include <iostream>

#include <FrostyMath.h>
#include <FrostyInput.h>

class Camera
{
public:
	inline Camera() : Camera(Vector3f::Zero) {}
	inline Camera(const Vector3f& position) : Camera(position, Vector3f::Forward, Vector3f::Up) {}
	inline Camera(const Vector3f& position, const Vector3f& forward, const Vector3f& up)  : m_Position(position), m_Forward(forward), m_Up(up) {}

	void Update();

	void Move(const Vector3f& direction, float speed);
	inline void Rotate(float angleX, float angleY) { this->Rotate(Vector2f(angleX, angleY)); }
	void Rotate(const Vector2f& angles);

	inline Vector3f& GetPosition() { return this->m_Position; }
	inline void SetPosition(const Vector3f& position) { this->m_Position = position; }

	inline Vector3f& GetForward() { return this->m_Forward; }
	inline void SetForward(const Vector3f& forward) { this->m_Forward = forward; }

	inline Vector3f& GetUp() { return this->m_Up; }
	inline void SetUp(const Vector3f& up) { this->m_Up = up; }

	inline Vector3f GetLeft() const { return this->m_Forward.Cross(this->m_Up).Normalized(); }
	inline Vector3f GetRight() const { return this->m_Up.Cross(this->m_Forward).Normalized(); }
private:
	Vector3f m_Position;
	Vector3f m_Forward;
	Vector3f m_Up;
};