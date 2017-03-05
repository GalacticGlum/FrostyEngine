#include <Graphics/Camera.h>

bool mouseLocked = false;
bool lockRotation = false;
void Camera::Update(float deltaTime)
{
	float movementSpeed = (float)(10.0f * deltaTime);
	float sensitivity = 0.5f;

	if (Input::GetKeyDown(Key::KEY_GRAVE_ACCENT))
	{
		lockRotation = !lockRotation;
	}

	if (!lockRotation)
	{
		if (Input::GetKey(Key::KEY_ESCAPE))
		{
			Input::ShowCursor(true);
			mouseLocked = false;
		}

		if (mouseLocked)
		{
			Vector2f centerPosition = Vector2f((float)800 / 2.0f, (float)600 / 2.0f);
			Vector2f deltaPos = Input::GetMousePosition() - centerPosition;

			bool rotY = deltaPos.X != 0;
			bool rotX = deltaPos.Y != 0;

			if (rotY)
			{
				this->Rotate(0, FrostyMath::DegreesToRadians(deltaPos.X * sensitivity));
			}
			if (rotX)
			{
				this->Rotate(FrostyMath::DegreesToRadians(deltaPos.Y * sensitivity), 0);
			}

			if (rotY || rotX)
			{
				Input::SetMousePosition(centerPosition);
			}
		}

		if (Input::GetMouseButtonDown(MouseButton::MOUSE_BUTTON_LEFT))
		{
			Vector2f centerPosition = Vector2f((float)800 / 2.0f, (float)600 / 2.0f);
			Input::ShowCursor(false);
			Input::SetMousePosition(centerPosition);
			mouseLocked = true;
		}
	}

	if (Input::GetKey(Key::KEY_W))
	{
		this->Move(this->GetForward(), -movementSpeed);
	}

	if (Input::GetKey(Key::KEY_S))
	{
		this->Move(this->GetForward(), movementSpeed);
	}

	if (Input::GetKey(Key::KEY_A))
	{
		this->Move(this->GetLeft(), movementSpeed);
	}

	if (Input::GetKey(Key::KEY_D))
	{
		this->Move(this->GetRight(), movementSpeed);
	}
}

void Camera::Move(const Vector3f& direction, float speed)
{
	this->m_Position += (direction * speed);
}

void Camera::Rotate(const Vector2f& angles)
{
	Vector3f horizontalAxis = Vector3f::Up.Cross(m_Forward).Normalized();

	if (angles.X != 0)
	{
		this->m_Forward = this->m_Forward.Rotate(angles.X, horizontalAxis).Normalized();
		this->m_Up = this->m_Forward.Cross(horizontalAxis).Normalized();
	}

	if (angles.Y != 0)
	{
		this->m_Forward = this->m_Forward.Rotate(angles.Y, Vector3f::Up).Normalized();
		this->m_Up = this->m_Forward.Cross(horizontalAxis).Normalized();
	}
}

const Matrix4f Camera::GetViewProjection() const
{
	Matrix4f cameraProjection = Matrix4f::Perspective(this->FOV, this->WIDTH / this->HEIGHT, this->Z_NEAR, this->Z_FAR);
	Matrix4f cameraRotation = Matrix4f::Rotate(this->GetForward(), this->GetUp());
	Matrix4f cameraTransformation = Matrix4f::Translate(this->GetPosition().Negative());

	Matrix4f camera = cameraProjection * cameraRotation * cameraTransformation;
	return camera;
}