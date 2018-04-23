#pragma once

#include <ostream>

struct Vec2
{
public:
	union
	{
		struct { float x, y; };
		struct { float r, g; };
	};
	static size_t size;

public:
	Vec2();
	Vec2(float _x);
	Vec2(float _x, float _y);
	Vec2(const Vec2& copy);

	const Vec2& operator=(const Vec2& vector);
	float& operator[](size_t index);
	const float& operator[](size_t index) const;

	Vec2 operator-();
	Vec2& operator++();
	const Vec2& operator++(int);
	Vec2& operator--();
	const Vec2& operator--(int);

	friend Vec2 operator+(const Vec2 left, float right);
	friend Vec2 operator+(float right, const Vec2 left);
	friend Vec2 operator+(const Vec2 left, const Vec2 right);

	friend Vec2 operator-(const Vec2 left, float right);
	friend Vec2 operator-(float right, const Vec2 left);
	friend Vec2 operator-(const Vec2 left, const Vec2 right);

	friend Vec2 operator*(const Vec2 left, float right);
	friend Vec2 operator*(float right, const Vec2 left);
	friend Vec2 operator*(const Vec2 left, const Vec2 right);

	friend Vec2 operator/(const Vec2 left, float right);
	friend Vec2 operator/(float right, const Vec2 left);
	friend Vec2 operator/(const Vec2 left, const Vec2 right);

	friend std::ostream& operator<<(std::ostream& ost, const Vec2& vector);

	static float magnitud(const Vec2& vector);
	static float dot(const Vec2& left, const Vec2& right);
	static Vec2 normalize(const Vec2& vector);
};