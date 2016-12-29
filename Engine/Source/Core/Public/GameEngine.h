#pragma once

#include <iostream>
#include <chrono>
#include <thread>

#include <FrostyCommon.h>
#include <GameInstance.h>

class Window;
class FROSTY_CORE_API GameEngine
{
public:
	GameEngine() : GameEngine(800, 600, 60) {}
	GameEngine(int width, int height) : GameEngine(width, height, 60) {}
	GameEngine(int width, int height, double frameRate) : m_FrameTime(1.0 / frameRate), m_Running(false), m_Width(width), m_Height(height) {}

	void Start();
	void Stop();

	inline int GetUPS() { return this->m_UpdatesPerSecond; }
	inline int GetFPS() { return this->m_FramesPerSecond; }
private:
	Window* m_Window;
	GameInstance* m_GameInstance;

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