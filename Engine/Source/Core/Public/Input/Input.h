#pragma once

#include <iostream>

#include <FrostyCore.h>
#include <FrostyMath.h>

class InputManager;
enum class Key;
enum class MouseButton;
class Window;
class FROSTY_CORE_API Input
{
public:
	static void Initialize(Window* window);
	static void Update();
	
	static bool GetKey(Key key);
	static bool GetKeyDown(Key key);
	static bool GetKeyUp(Key key);

	static bool GetMouseButton(MouseButton mouseButton);
	static bool GetMouseButtonDown(MouseButton mouseButton);
	static bool GetMouseButtonUp(MouseButton mouseButton);

	static Vector2f GetMousePosition();
	inline static void SetMousePosition(float x, float y) { SetMousePosition(Vector2f(x, y)); }
	static void SetMousePosition(const Vector2f& position);

	static bool GetCursorVisibility();
	static void ShowCursor(bool visibility);
private:
	static InputManager* m_InputManager;
};