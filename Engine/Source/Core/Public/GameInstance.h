#pragma once

#include <iostream>
#include <FrostyCore.h>
#include <Input/Input.h>

class GameInstance
{
public:
	virtual void Start() {}
	virtual void Update() {}
	virtual void Tick() {}
	virtual void Render() {}
	virtual void Shutdown() {}

};