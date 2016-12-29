#pragma once

#include <FrostyCore.h>

class GameInstance
{
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Shutdown() = 0;

	virtual void Tick() {}
};