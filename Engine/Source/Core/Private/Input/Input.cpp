#include <Input/Input.h>

#include <FrostyGraphics.h>
#include <FrostyInput.h>

InputManager* Input::m_InputManager = nullptr;

void Input::Initialize(Window* window)
{ 
	m_InputManager = new InputManager(window); 
}

void Input::Update() 
{ 
	return m_InputManager->Update();
}

bool Input::GetKey(Key key) 
{ 
	return m_InputManager->GetKey(key); 
}

bool Input::GetKeyDown(Key key) 
{ 
	return m_InputManager->GetKeyDown(key); 
}

bool Input::GetKeyUp(Key key) 
{ 
	return m_InputManager->GetKeyUp(key); 
}

bool Input::GetMouseButton(MouseButton mouseButton)
{
	return m_InputManager->GetMouseButton(mouseButton);
}

bool Input::GetMouseButtonDown(MouseButton mouseButton)
{
	return m_InputManager->GetMouseButtonDown(mouseButton);
}

bool Input::GetMouseButtonUp(MouseButton mouseButton)
{
	return m_InputManager->GetMouseButtonUp(mouseButton);
}

Vector2f Input::GetMousePosition()
{
	return m_InputManager->GetMousePosition();
}

void Input::SetMousePosition(const Vector2f& position)
{
	m_InputManager->SetMousePosition(position);
}

bool Input::GetCursorVisibility() 
{ 
	return m_InputManager->GetCursorVisibility(); 
}

void Input::ShowCursor(bool visibility)
{ 
	m_InputManager->ShowCursor(visibility); 
}