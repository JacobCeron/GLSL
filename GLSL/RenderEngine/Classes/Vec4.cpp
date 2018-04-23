#include <assert.h>
#include <cmath>

#include "Vec4.h"

size_t Vec4::size{ 3 };

Vec4::Vec4()
	: x{ 0 }, y{ 0 }, z{ 0 }, w{ 0 }
{}

Vec4::Vec4(float _x)
	: x{ _x }, y{ _x }, z{ _x }, w{ _x }
{}

Vec4::Vec4(float _x, float _y, float _z, float _w)
	: x{ _x }, y{ _y }, z{ _z }, w{ _w }
{}

Vec4::Vec4(const Vec4& copy)
	: x{ copy.x }, y{ copy.y }, z{ copy.z }, w{ copy.w }
{}

const Vec4& Vec4::operator=(const Vec4& vector)
{
	assert(this != &vector);
	x = vector.x;
	y = vector.y;
	z = vector.z;
	w = vector.w;

	return *this;
}

float& Vec4::operator[](size_t index)
{
	assert(index >= 0 && index < size);
	return (&x)[index];
}

const float& Vec4::operator[](size_t index) const
{
	assert(index >= 0 && index < size);
	return (&x)[index];
}

Vec4 Vec4::operator-()
{
	return Vec4(-x, -y, -z, -w);
}

Vec4& Vec4::operator++()
{
	++x;
	++y;
	++z;
	++w;
	return *this;
}

const Vec4& Vec4::operator++(int)
{
	Vec4 temp(*this);
	x++;
	y++;
	z++;
	w++;
	return temp;
}

Vec4& Vec4::operator--()
{
	--x;
	--y;
	--z;
	--w;
	return *this;
}

const Vec4& Vec4::operator--(int)
{
	Vec4 temp(*this);
	x--;
	y--;
	z--;
	w--;
	return temp;
}

Vec4 operator+(const Vec4 left, float right)
{
	return Vec4
	(
		left.x + right,
		left.y + right,
		left.z + right,
		left.w + right
	);
}

Vec4 operator+(float left, const Vec4 right)
{
	return Vec4
	(
		left + right.x,
		left + right.y,
		left + right.z,
		left + right.w
	);
}

Vec4 operator+(const Vec4 left, const Vec4 right)
{
	return Vec4
	(
		left.x + right.x,
		left.y + right.y,
		left.z + right.z,
		left.w + right.w
	);
}

Vec4 operator-(const Vec4 left, float right)
{
	return Vec4
	(
		left.x - right,
		left.y - right,
		left.z - right,
		left.w - right
	);
}

Vec4 operator-(float left, const Vec4 right)
{
	return Vec4
	(
		left - right.x,
		left - right.y,
		left - right.z,
		left - right.w
	);
}

Vec4 operator-(const Vec4 left, const Vec4 right)
{
	return Vec4
	(
		left.x - right.x,
		left.y - right.y,
		left.z - right.z,
		left.w - right.w
	);
}

Vec4 operator*(const Vec4 left, float right)
{
	return Vec4
	(
		left.x * right,
		left.y * right,
		left.z * right,
		left.w * right
	);
}

Vec4 operator*(float left, const Vec4 right)
{
	return Vec4
	(
		left * right.x,
		left * right.y,
		left * right.z,
		left * right.w
	);
}

Vec4 operator*(const Vec4 left, const Vec4 right)
{
	return Vec4
	(
		left.x * right.x,
		left.y * right.y,
		left.z * right.z,
		left.w * right.w
	);
}

Vec4 operator/(const Vec4 left, float right)
{
	return Vec4
	(
		left.x / right,
		left.y / right,
		left.z / right,
		left.w / right
	);
}

Vec4 operator/(float left, const Vec4 right)
{
	return Vec4
	(
		left / right.x,
		left / right.y,
		left / right.z,
		left / right.w
	);
}

Vec4 operator/(const Vec4 left, const Vec4 right)
{
	return Vec4
	(
		left.x / right.x,
		left.y / right.y,
		left.z / right.z,
		left.w / right.w
	);
}

std::ostream& operator<<(std::ostream & ost, const Vec4 & vector)
{
	ost << vector.x << " " << vector.y << " " << vector.z << " " << vector.w;
	return ost;
}

float Vec4::magnitud(const Vec4& vector)
{
	return sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w);
}

float Vec4::dot(const Vec4& left, const Vec4& right)
{
	return (left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w);
}

Vec4 Vec4::normalize(const Vec4& vector)
{
	float length{ magnitud(vector) };
	return Vec4(vector / length);
}