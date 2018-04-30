#pragma once

#include <string>

class GameObject;

class Component
{
public:
	GameObject* gameObject;
private:
	std::string m_name;

public:
	Component();

	template<typename T>
	Component* getComponent();

	void setName(const std::string& name);
	std::string getName() const;

	bool operator()();
	friend bool operator==(const Component& left, const Component& right);
	friend bool operator!=(const Component& left, const Component& right);
};

template<typename T>
Component* Component::getComponent()
{
	if (components.count(typeid(T).raw_name()))
		return gameObject->components[typeid(T).raw_name()];
	else
		return nullptr
}