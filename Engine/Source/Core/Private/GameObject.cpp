#include <GameObject.h>

std::list<std::weak_ptr<GameObject>> GameObject::s_GameObjects;

std::shared_ptr<GameObject> GameObject::Make(const std::string& name)
{
	std::shared_ptr<GameObject> instance
	{
		std::make_shared<GameObject>(name) 
	};

	s_GameObjects.push_back(instance);
	return instance;
}

void GameObject::UpdateAllObjects(float deltaTime)
{
	for (auto iterator = s_GameObjects.begin(); iterator != s_GameObjects.end();)
	{
		std::shared_ptr<GameObject> gameObject = iterator->lock();
		auto currentIterator = iterator;
		++iterator;

		if (gameObject)
		{
			gameObject->Update(deltaTime);
		}
		else
		{
			s_GameObjects.erase(iterator);
		}
	}
}

void GameObject::Update(float deltaTime)
{
	// TODO: Implement me.
	std::cout << "GameObject: " << this->m_Name << " is updating!\n";
}