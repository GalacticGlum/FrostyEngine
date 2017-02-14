#pragma once

#include <string>
#include <memory>

#include <FrostyCore.h>

class GameEngine;
class FROSTY_CORE_API Application
{
public:
	static void CreateContext(const std::string& windowTitle, int width, int height);
	static void Launch(GameInstance* gameInstance);
	inline static std::shared_ptr<GameEngine> GetEngine() { return s_GameEngine; }
private:
	static std::shared_ptr<GameEngine> s_GameEngine;
};