#include <Graphics/Camera.h>

Camera* Camera::m_Instance = nullptr;
void Camera::Move(const Vector3f& direction, float distance)
{
	this->m_Position += (direction * distance);
}

void Camera::Rotate(const Vector2f& rotation)
{
	Vector3f horizontalAxis = Vector3f::Up.Cross(m_Forward).Normalize();
	
	if (rotation.X != 0)
	{
		// X rotation
		this->m_Forward.Rotate(rotation.X, horizontalAxis).Normalize();
		this->m_Up = this->m_Forward.Cross(horizontalAxis).Normalize();
	}

	if (rotation.Y != 0)
	{
		// Y rotation
		this->m_Forward.Rotate(rotation.Y, Vector3f::Up).Normalize();
		this->m_Up = this->m_Forward.Cross(horizontalAxis).Normalize();
	}
}