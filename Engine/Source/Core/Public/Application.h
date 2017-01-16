#pragma once

#include <string>
#include <FrostyCore.h>

class GameInstance;
class GameEngine;
class FROSTY_CORE_API Application
{
public:
	static void Launch(const std::string& windowTitle, int width, int height, GameInstance* gameInstance);
	inline static GameEngine* GetEngine() { return m_GameEngine; }
private:
	static GameEngine* m_GameEngine;
};