#pragma once

#include <iostream>

#include <FrostyCore.h>
#include <FrostyMath.h>
#include <FrostyGraphics.h>

#define MAX_KEYS 512
#define MAX_MOUSE_BUTTONS 256

class Window;
class InputManager
{
public:
	InputManager(Window* window);
	void Update();

	inline bool GetKey(Key key) { return glfwGetKey(this->m_Window, (int)key) == GLFW_PRESS; }
	inline bool GetKeyDown(Key key) { return this->m_DownKeys[(int)key]; }
	inline bool GetKeyUp(Key key) { return this->m_UpKeys[(int)key]; }
	 
	inline bool GetMouseButton(MouseButton mouseButton) { return glfwGetMouseButton(this->m_Window, (int)mouseButton) == GLFW_PRESS; }
	inline bool GetMouseButtonDown(MouseButton mouseButton) { return this->m_DownMouseButtons[(int)mouseButton]; }
	inline bool GetMouseButtonUp(MouseButton mouseButton) { return this->m_UpMouseButtons[(int)mouseButton]; }

	inline Vector2f GetMousePosition() { return Vector2f(this->m_MouseX, this->m_MouseY); }
	inline void SetMousePosition(float x, float y) { this->SetMousePosition(Vector2f(x, y)); }
	inline void SetMousePosition(const Vector2f& position) { glfwSetCursorPos(this->m_Window, position.X, position.Y); }

	inline bool GetCursorVisibility() { return (glfwGetInputMode(this->m_Window, GLFW_CURSOR) == GLFW_CURSOR_NORMAL); }
	inline void ShowCursor(bool visibility) { glfwSetInputMode(this->m_Window, GLFW_CURSOR, visibility ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN); }
private:
	bool m_Keys[MAX_KEYS];
	bool m_DownKeys[MAX_KEYS];
	bool m_UpKeys[MAX_KEYS];
	
	bool m_MouseButtons[MAX_MOUSE_BUTTONS];
	bool m_DownMouseButtons[MAX_MOUSE_BUTTONS];
	bool m_UpMouseButtons[MAX_MOUSE_BUTTONS];

	float m_MouseX;
	float m_MouseY;

	GLFWwindow* m_Window;

	friend static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
};