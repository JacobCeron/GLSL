#include <assert.h>
#include <cmath>

#include "Vec3.h"

size_t Vec3::size{ 3 };

Vec3::Vec3()
	: x{ 0 }, y{ 0 }, z{ 0 }
{}

Vec3::Vec3(float _x)
	: x{ _x }, y{ _x }, z{ _x }
{}

Vec3::Vec3(float _x, float _y, float _z)
	: x{ _x }, y{ _y }, z{ _z }
{}

Vec3::Vec3(const Vec3& copy)
	: x{ copy.x }, y{ copy.y }, z{ copy.z }
{}

const Vec3& Vec3::operator=(const Vec3& vector)
{
	assert(this != &vector);
	x = vector.x;
	y = vector.y;
	z = vector.z;

	return *this;
}

float& Vec3::operator[](size_t index)
{
	assert(index >= 0 && index < size);
	return (&x)[index];
}

const float& Vec3::operator[](size_t index) const
{
	assert(index >= 0 && index < size);
	return (&x)[index];
}

Vec3 Vec3::operator-()
{
	return Vec3(-x, -y, -z);
}

Vec3& Vec3::operator++()
{
	++x;
	++y;
	++z;
	return *this;
}

const Vec3& Vec3::operator++(int)
{
	Vec3 temp(*this);
	x++;
	y++;
	z++;
	return temp;
}

Vec3& Vec3::operator--()
{
	--x;
	--y;
	--z;
	return *this;
}

const Vec3& Vec3::operator--(int)
{
	Vec3 temp(*this);
	x--;
	y--;
	z--;
	return temp;
}

Vec3 operator+(const Vec3 left, float right)
{
	return Vec3
	(
		left.x + right,
		left.y + right,
		left.z + right
	);
}

Vec3 operator+(float left, const Vec3 right)
{
	return Vec3
	(
		left + right.x,
		left + right.y,
		left + right.z
	);
}

Vec3 operator+(const Vec3 left, const Vec3 right)
{
	return Vec3
	(
		left.x + right.x,
		left.y + right.y,
		left.z + right.z
	);
}

Vec3 operator-(const Vec3 left, float right)
{
	return Vec3
	(
		left.x - right,
		left.y - right,
		left.z - right
	);
}

Vec3 operator-(float left, const Vec3 right)
{
	return Vec3
	(
		left - right.x,
		left - right.y,
		left - right.z
	);
}

Vec3 operator-(const Vec3 left, const Vec3 right)
{
	return Vec3
	(
		left.x - right.x,
		left.y - right.y,
		left.z - right.z
	);
}

Vec3 operator*(const Vec3 left, float right)
{
	return Vec3
	(
		left.x * right,
		left.y * right,
		left.z * right
	);
}

Vec3 operator*(float left, const Vec3 right)
{
	return Vec3
	(
		left * right.x,
		left * right.y,
		left * right.z
	);
}

Vec3 operator*(const Vec3 left, const Vec3 right)
{
	return Vec3
	(
		left.x * right.x,
		left.y * right.y,
		left.z * right.z
	);
}

Vec3 operator/(const Vec3 left, float right)
{
	return Vec3
	(
		left.x / right,
		left.y / right,
		left.z / right
	);
}

Vec3 operator/(float left, const Vec3 right)
{
	return Vec3
	(
		left / right.x,
		left / right.y,
		left / right.z
	);
}

Vec3 operator/(const Vec3 left, const Vec3 right)
{
	return Vec3
	(
		left.x / right.x,
		left.y / right.y,
		left.z / right.z
	);
}

std::ostream& operator<<(std::ostream & ost, const Vec3 & vector)
{
	ost << vector.x << " " << vector.y << " " << vector.z;
	return ost;
}

float Vec3::magnitud(const Vec3& vector)
{
	return sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

float Vec3::dot(const Vec3& left, const Vec3& right)
{
	return (left.x * right.x + left.y * right.y + left.z * right.z);
}

Vec3 Vec3::normalize(const Vec3& vector)
{
	float length{ magnitud(vector) };
	return Vec3(vector / length);
}