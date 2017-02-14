#pragma once

class GameInstance
{
public:
	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual void Shutdown() = 0;

	virtual void Tick() {}
};