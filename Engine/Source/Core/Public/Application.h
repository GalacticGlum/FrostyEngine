#pragma once

#include <FrostyCore.h>

class GameEngine;
class GameInstance;
class FROSTY_CORE_API Application
{
public:
	static void Launch(int width, int height, GameInstance* gameInstance);
	static GameEngine* GetGameEngineInstance() { return m_GameEngineInstance; }
private:
	static GameEngine* m_GameEngineInstance;
};
