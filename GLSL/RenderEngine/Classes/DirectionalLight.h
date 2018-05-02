#pragma once

#include <vector>
#include "Behaviour.h"
#include "Maths.h"

class DirectionalLight
	: public Behaviour
{
public:
	static std::vector<DirectionalLight*> currentLights;
private:
	Vector4 m_color;

public:
	DirectionalLight();

	void setColor(const Vector4& color);
	Vector4 getColor() const;
};