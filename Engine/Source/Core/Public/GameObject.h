#pragma once

#include <string>
#include <list>
#include <memory.h>

#include <FrostyCore.h>

class FROSTY_CORE_API GameObject
{
public:
	static std::shared_ptr<GameObject> Make(const std::string& name);
	static void UpdateAllObjects(float deltaTime);

	inline explicit GameObject(const std::string& name) : m_Name(name) { }
	~GameObject() = default;

	GameObject(const GameObject& other) = delete;
	GameObject(GameObject&& other) = delete;

	GameObject& operator=(const GameObject& other) = delete;
	GameObject& operator=(GameObject&& other) = delete;

private:
	std::string m_Name;
	void Update(float deltaTime);

	// TODO: Implement children
	// TODO: Implement components

	static std::list<std::weak_ptr<GameObject>> s_GameObjects;
};