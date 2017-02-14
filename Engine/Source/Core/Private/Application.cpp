#include <Application.h>

std::shared_ptr<GameEngine> Application::s_GameEngine;

void Application::CreateContext(const std::string& windowTitle, int width, int height)
{
	Application::s_GameEngine = std::make_shared<GameEngine>(width, height, windowTitle);
}

void Application::Launch(GameInstance* gameInstance)
{
	Application::s_GameEngine->Start(gameInstance);
}