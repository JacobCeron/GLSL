#pragma once

#include <ostream>

#include "Maths.h"

class Quaternion
{
public:
	struct { float x, y, z, w; };

public:
	Quaternion();
	Quaternion(float _x, float _y, float _z, float _w);
	Quaternion(const Vector3& n, float a);
	Quaternion(const Quaternion& copy);

	static Quaternion inverse(const Quaternion& rotation);

	friend Quaternion operator*(const Quaternion& left, const Quaternion& right);
	friend Vector3 operator*(const Quaternion& rotation, const Vector3& point);

	friend std::ostream& operator<<(std::ostream& ost, const Quaternion& quaternion);
};