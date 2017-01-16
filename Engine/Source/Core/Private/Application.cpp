#include <Application.h>
#include <FrostyCore.h>

GameEngine* Application::m_GameEngine = nullptr;
void Application::Launch(const std::string& windowTitle, int width, int height, GameInstance* gameInstance)
{
	Application::m_GameEngine = new GameEngine(gameInstance, width, height, windowTitle);
	Application::m_GameEngine->Start();
}