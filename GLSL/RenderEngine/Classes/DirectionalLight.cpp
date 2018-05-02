#include "DirectionalLight.h"
#include "GameObject.h"

std::vector<DirectionalLight*> DirectionalLight::currentLights;

DirectionalLight::DirectionalLight()
	: m_color(1.0f, 0.9568f, 0.8392f, 1.0f)
{
	currentLights.push_back(this);
}

void DirectionalLight::setColor(const Vector4 & color)
{
	m_color = color;
}

Vector4 DirectionalLight::getColor() const
{
	return m_color;
}