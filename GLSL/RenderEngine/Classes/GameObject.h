#pragma once

#include <string>
#include <map>
#include "Transform.h"

class GameObject
{
public:
	Transform transform;
private:
	std::string m_name;
	std::map<std::string, Component*> components;

public:
	GameObject();
	GameObject(const std::string& name);

	void setName(const std::string& name);
	std::string getName() const;

	template<typename T>
	T* addComponent();
	template<typename T>
	T* getComponent();

	friend bool operator==(const GameObject& left, const GameObject& right);
	friend bool operator!=(const GameObject& left, const GameObject& right);

	friend class Component;
};

template<typename T>
T* GameObject::addComponent()
{
	if (components.count(typeid(T).raw_name()))
		return nullptr;

	T* newComponent = new T;
	components[typeid(T).raw_name()] = newComponent;
	newComponent->gameObject = this;
	return newComponent;
}

template<typename T>
T* GameObject::getComponent()
{
	if (components.count(typeid(T).raw_name()))
		return static_cast<T*>(components[typeid(T).raw_name()]);
	else
		return nullptr;
}