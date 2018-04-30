#include "GameObject.h"
#include "Component.h"

GameObject::GameObject()
	: GameObject( "GameObject" )
{}

GameObject::GameObject(const std::string& name)
	: m_name{ name }
{
	components[typeid(Transform).raw_name()] = &transform;
	transform.gameObject = this;
}

void GameObject::setName(const std::string& name)
{
	m_name = name;
}

std::string GameObject::getName() const
{
	return m_name;
}

bool operator==(const GameObject& left, const GameObject& right)
{
	return (&left == &right);
}

bool operator!=(const GameObject& left, const GameObject& right)
{
	return !(left == right);
}