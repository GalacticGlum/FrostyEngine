#include <Graphics/Window.h>

void WindowResizeCallback(GLFWwindow* window, int width, int height);

Window::Window(std::string title, int width, int height) : 
	m_Title(title), m_Width(width), m_Height(height)
{
	if (!this->Initialize())
	{
		glfwTerminate();
	}

	// TODO: MOVE ME!!!
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::Initialize()
{
	if (!glfwInit())
	{
		std::cout << "Window::Initialize: Failed to initialize GLFW!\n";
		return false;
	}

	this->m_Window = glfwCreateWindow(this->m_Width, this->m_Height, this->m_Title.c_str(), nullptr, nullptr);
	if (!this->m_Window)
	{
		std::cout << "Window::Initialize: Failed to create window!\n";
		return false;
	}

	glfwMakeContextCurrent(this->m_Window);
	glfwSetWindowSizeCallback(this->m_Window, WindowResizeCallback);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Window::Initialize: Failed to initialize GLEW!\n";
		return false;
	}
	
	std::cout << "OpenGL " << glGetString(GL_VERSION) << "\n";
	return true;
} 

void Window::Clear()
{
	glfwMakeContextCurrent(this->m_Window);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Update()
{
	glfwPollEvents();
	glfwSwapBuffers(this->m_Window);
}

void WindowResizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}