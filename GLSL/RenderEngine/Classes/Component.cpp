#include "Component.h"
#include "GameObject.h"

Component::Component()
{
	gameObject = nullptr;
}

void Component::setName(const std::string & name)
{
	gameObject->setName(name);
}

std::string Component::getName() const
{
	return gameObject->getName();
}

bool Component::operator()()
{
	return (this != nullptr && gameObject != nullptr);
}

bool operator==(const Component & left, const Component & right)
{
	return (&left == &right);
}

bool operator!=(const Component & left, const Component & right)
{
	return !(left == right);
}