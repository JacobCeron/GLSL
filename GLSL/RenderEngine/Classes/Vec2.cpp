#include <assert.h>
#include <cmath>

#include "Vec2.h"

size_t Vec2::size{ 2 };

Vec2::Vec2()
	: x{ 0 }, y{ 0 }
{}

Vec2::Vec2(float _x)
	: x{ _x }, y{ _x }
{}

Vec2::Vec2(float _x, float _y)
	: x{ _x }, y{ _y }
{}

Vec2::Vec2(const Vec2& copy)
	: x{ copy.x }, y{ copy.y }
{}

const Vec2& Vec2::operator=(const Vec2& vector)
{
	assert(this != &vector);
	x = vector.x;
	y = vector.y;

	return *this;
}

float& Vec2::operator[](size_t index)
{
	assert(index >= 0 && index < size);
	return (&x)[index];
}

const float& Vec2::operator[](size_t index) const
{
	assert(index >= 0 && index < size);
	return (&x)[index];
}

Vec2 Vec2::operator-()
{
	return Vec2(-x, -y);
}

Vec2& Vec2::operator++()
{
	++x;
	++y;
	return *this;
}

const Vec2& Vec2::operator++(int)
{
	Vec2 temp(*this);
	x++;
	y++;
	return temp;
}

Vec2& Vec2::operator--()
{
	--x;
	--y;
	return *this;
}

const Vec2& Vec2::operator--(int)
{
	Vec2 temp(*this);
	x--;
	y--;
	return temp;
}

Vec2 operator+(const Vec2 left, float right)
{
	return Vec2
	(
		left.x + right,
		left.y + right
	);
}

Vec2 operator+(float left, const Vec2 right)
{
	return Vec2
	(
		left + right.x,
		left + right.y
	);
}

Vec2 operator+(const Vec2 left, const Vec2 right)
{
	return Vec2
	(
		left.x + right.x,
		left.y + right.y
	);
}

Vec2 operator-(const Vec2 left, float right)
{
	return Vec2
	(
		left.x - right,
		left.y - right
	);
}

Vec2 operator-(float left, const Vec2 right)
{
	return Vec2
	(
		left - right.x,
		left - right.y
	);
}

Vec2 operator-(const Vec2 left, const Vec2 right)
{
	return Vec2
	(
		left.x - right.x,
		left.y - right.y
	);
}

Vec2 operator*(const Vec2 left, float right)
{
	return Vec2
	(
		left.x * right,
		left.y * right
	);
}

Vec2 operator*(float left, const Vec2 right)
{
	return Vec2
	(
		left * right.x,
		left * right.y
	);
}

Vec2 operator*(const Vec2 left, const Vec2 right)
{
	return Vec2
	(
		left.x * right.x,
		left.y * right.y
	);
}

Vec2 operator/(const Vec2 left, float right)
{
	return Vec2
	(
		left.x / right,
		left.y / right
	);
}

Vec2 operator/(float left, const Vec2 right)
{
	return Vec2
	(
		left / right.x,
		left / right.y
	);
}

Vec2 operator/(const Vec2 left, const Vec2 right)
{
	return Vec2
	(
		left.x / right.x,
		left.y / right.y
	);
}

std::ostream& operator<<(std::ostream & ost, const Vec2 & vector)
{
	ost << vector.x << " " << vector.y;
	return ost;
}

float Vec2::magnitud(const Vec2& vector)
{
	return sqrtf( vector.x * vector.x + vector.y * vector.y );
}

float Vec2::dot(const Vec2& left, const Vec2& right)
{
	return (left.x * right.x + left.y * right.y);
}

Vec2 Vec2::normalize(const Vec2& vector)
{
	float length{ magnitud(vector) };
	return Vec2(vector / length);
}