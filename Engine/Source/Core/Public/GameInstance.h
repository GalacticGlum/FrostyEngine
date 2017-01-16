#pragma once

#include <iostream>
#include <FrostyCore.h>
#include <Input/Input.h>

class GameInstance
{
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Shutdown() = 0;

	virtual void Tick() {}
};