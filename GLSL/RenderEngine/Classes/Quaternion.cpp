#include "Quaternion.h"

#include <iostream>

Quaternion::Quaternion()
{
}

Quaternion::Quaternion(float _x, float _y, float _z, float _w)
{
	_w = radians(_w);
	std::cout << _w << std::endl;
	w = cos(_w / 2);
	x = _x * sin(_w / 2);
	y = _y * sin(_w / 2);
	z = _z * sin(_w / 2);
}

Quaternion::Quaternion(const Vector3 & n, float a)
	: Quaternion(n.x, n.y, n.z, a)
{}

Quaternion::Quaternion(const Quaternion& copy)
	: x{ copy.x }, y{ copy.y }, z{ copy.z }, w{ copy.w }
{}

Quaternion Quaternion::inverse(const Quaternion & rotation)
{
	return Quaternion(-rotation.x, -rotation.y, -rotation.z, rotation.w);
}

Quaternion operator*(const Quaternion& left, const Quaternion& right)
{
	Vector3 vleft(left.x, left.y, left.z);
	Vector3 vright(right.x, right.y, right.z);

	Quaternion result;

	float w(left.w * right.w - Vector3::dot(vleft, vright));
	Vector3 n (vleft * right.w + vright * left.w + Vector3::cross(vleft, vright));

	result.x = n.x;
	result.y = n.y;
	result.z = n.z;
	result.w = w;

	return result;
}

Vector3 operator*(const Quaternion& rotation, const Vector3& point)
{
	Vector3 rotationVector(rotation.x, rotation.y, rotation.z);
	Vector3 v(Vector3::cross(rotationVector, point));

	return Vector3(point + 2.0f * rotation.w * v + 2.0f * Vector3::cross(rotationVector, v));
}

std::ostream& operator<<(std::ostream& ost, const Quaternion& quaternion)
{
	ost << quaternion.x << " " << quaternion.y << " " << quaternion.z << " " << quaternion.w;
	return ost;
}