#pragma once

#include <iostream>
#include <string>

#include <FrostyCore.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class FROSTY_CORE_API Window
{
public:
	Window(std::string title, int width, int height);
	~Window();

	void Clear();
	void Update();

	inline bool IsClosed() { return glfwWindowShouldClose(this->m_Window) == 1; }
	inline int GetWidth() { return this->m_Width; }
	inline int GetHeight() { return this->m_Height; }

	void SetTitle(std::string title) 
	{
		this->m_Title = title;
		glfwSetWindowTitle(this->m_Window, this->m_Title.c_str());
	}

	void SetClearColour(float red, float green, float blue, float alpha) { glClearColor(red, green, blue, alpha); }
private:
	GLFWwindow* m_Window;

	std::string m_Title;
	int m_Width;
	int m_Height;

	bool Initialize();
};