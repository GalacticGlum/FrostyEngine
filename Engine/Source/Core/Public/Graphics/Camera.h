#pragma once

#include <FrostyCore.h>
#include <FrostyMath.h>

class FROSTY_CORE_API Camera
{
public:
	inline static Camera* GetInstance() { return m_Instance; }

	inline Camera() : Camera(Vector3f::Zero, Vector3f::Forward, Vector3f::Up) {}
	inline Camera(Vector3f position, Vector3f forward, Vector3f up) : m_Position(position), m_Forward(forward.Normalize()), m_Up(up.Normalize()) { this->m_Instance = this; }

	void Move(const Vector3f& direction, float distance);
	inline void Rotate(float angleX, float angleY) { this->Rotate(Vector2f(angleX, angleY)); }
	void Rotate(const Vector2f& angles);

	inline Vector3f& GetPosition() { return this->m_Position; }
	inline void SetPosition(const Vector3f& position) { this->m_Position = position; }

	inline Vector3f& GetForward() { return this->m_Forward; }
	inline void SetForward(const Vector3f& forward) { this->m_Forward = forward; }
	
	inline Vector3f& GetUp() { return this->m_Up; }
	inline void SetUp(const Vector3f& up) { this->m_Up = up; }

	inline Vector3f& GetLeft() const { return this->m_Forward.Cross(this->m_Up).Normalize(); }
	inline Vector3f& GetRight() const { return this->m_Up.Cross(this->m_Forward).Normalize(); }
private:
	static Camera* m_Instance;

	Vector3f m_Position;

	// TODO: Switch with quaternion
	Vector3f m_Forward;
	Vector3f m_Up;
};