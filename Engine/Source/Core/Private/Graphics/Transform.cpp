#include <Graphics/Transform.h>
#include <FrostyGraphics.h>

Transform::Transform() : m_Position(Vector3f::Zero), m_Rotation(Vector3f::Zero), m_Scale(Vector3f::One) {}
Matrix4f Transform::GetTransformation()
{
	Matrix4f translation = Matrix4f::Translate(this->m_Position);
	Matrix4f rotation = Matrix4f::Rotate(this->m_Rotation);
	Matrix4f scale = Matrix4f::Scale(this->m_Scale);

	return translation * rotation * scale;
}