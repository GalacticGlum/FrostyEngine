#pragma once

#include <iostream>
#include <chrono>
#include <thread>

#include <cmath>

#include <FrostyCommon.h>
#include <GameInstance.h>
#include <Utilities/Random.h>

class Window;
class FROSTY_CORE_API GameEngine
{
public:
	inline GameEngine(GameInstance* gameInstance) : GameEngine(gameInstance, 800, 600) {}
	inline GameEngine(GameInstance* gameInstance, int width, int height) : GameEngine(gameInstance, width, height, "Frosty Engine: Window", 60) {}
	inline GameEngine(GameInstance* gameInstance, int width, int height, const std::string& windowTitle) : GameEngine(gameInstance, width, height, windowTitle, 60) {}
	inline GameEngine(GameInstance* gameInstance, int width, int height, const std::string& windowTitle, double frameRate) : m_FrameTime(1.0 / frameRate), m_Running(false), m_Width(width), m_Height(height), m_GameInstance(gameInstance), m_WindowTitle(windowTitle) {}

	void Start();
	void Stop();

	inline int GetUPS() { return this->m_UpdatesPerSecond; }
	inline int GetFPS() { return this->m_FramesPerSecond; }
	inline Window* GetWindow() { return this->m_Window; }

private:
	Window* m_Window;
	GameInstance* m_GameInstance;

	std::string m_WindowTitle;

	bool m_Running;
	double m_FrameTime;

	int m_UpdatesPerSecond;
	int m_FramesPerSecond;

	int m_Width;
	int m_Height;

	void Run();
	void Render();
	void Shutdown();
};