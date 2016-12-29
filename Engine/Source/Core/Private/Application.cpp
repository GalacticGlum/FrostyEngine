#include <Application.h>
#include <GameEngine.h>
#include <GameInstance.h>

GameEngine* Application::m_GameEngineInstance = nullptr;
void Application::Launch(int width, int height, GameInstance* gameInstance)
{
	Application::m_GameEngineInstance = new GameEngine(width, height, gameInstance);
	Application::m_GameEngineInstance->Start();
}