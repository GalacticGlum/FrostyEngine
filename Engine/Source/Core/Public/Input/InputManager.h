#pragma once

#include <iostream>

#include <FrostyCore.h>
#include <FrostyGraphics.h>

#define MAX_KEYS 512
#define MAX_MOUSE_BUTTONS 256

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

	//Vecto2f GetMousePosition();
	//inline void SetMousePosition(float x, float y);
	//void SetMousePosition(const Vector2f& position);

	inline bool GetCursorVisibility() { return (glfwGetInputMode(this->m_Window, GLFW_CURSOR) == GLFW_CURSOR_NORMAL); }
	inline void ShowCursor(bool visibility) { glfwSetInputMode(this->m_Window, GLFW_CURSOR, visibility ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN); }
private:
	bool m_Keys[MAX_KEYS];
	bool m_DownKeys[MAX_KEYS];
	bool m_UpKeys[MAX_KEYS];
	
	bool m_MouseButtons[MAX_MOUSE_BUTTONS];
	bool m_DownMouseButtons[MAX_MOUSE_BUTTONS];
	bool m_UpMouseButtons[MAX_MOUSE_BUTTONS];

	double m_MouseX;
	double m_MouseY;

	GLFWwindow* m_Window;

	friend static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
};