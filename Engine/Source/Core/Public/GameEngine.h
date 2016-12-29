#pragma once

#include <memory>
#include <thread>
#include <cstdint>
#include <iostream>

#include <Utilities/Time.h>
#include <GameInstance.h>

class Window;
class FROSTY_CORE_API GameEngine
{
public:
	GameEngine(GameInstance* gameInstance) : GameEngine(800, 600, 60, gameInstance) {}
	GameEngine(int width, int height, GameInstance* gameInstance) : GameEngine(width, height, 60, gameInstance) {}
	GameEngine(int width, int height, double frameRate, GameInstance* gameInstance) : m_GameInstance(gameInstance), m_FrameTime(1.0 / frameRate), m_Running(false) {}

	void Start();
	inline void Stop() { this->m_Running = false; }

	inline int GetUPS() { return this->m_UpdatesPerSecond; }
	inline int GetFPS() { return this->m_FramesPerSecond; }
	inline Window* GetWindow() { return this->m_Window; }
	inline double GetDeltaTime() { return this->m_DeltaTime; }
private:
	void Run();
	void Render();
	void Shutdown();

	GameInstance* m_GameInstance;
	Window* m_Window;

	bool m_Running;
	double m_DeltaTime;
	double m_FrameTime;

	int m_UpdatesPerSecond;
	int m_FramesPerSecond;
};