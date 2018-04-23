#pragma once

#include <ostream>

struct Vec4
{
public:
	union
	{
		struct { float x, y, z, w; };
		struct { float r, g, b, a; };
	};
	static size_t size;

public:
	Vec4();
	Vec4(float _x);
	Vec4(float _x, float _y, float _z, float _w);
	Vec4(const Vec4& copy);

	const Vec4& operator=(const Vec4& vector);
	float& operator[](size_t index);
	const float& operator[](size_t index) const;

	Vec4 operator-();
	Vec4& operator++();
	const Vec4& operator++(int);
	Vec4& operator--();
	const Vec4& operator--(int);

	friend Vec4 operator+(const Vec4 left, float right);
	friend Vec4 operator+(float right, const Vec4 left);
	friend Vec4 operator+(const Vec4 left, const Vec4 right);

	friend Vec4 operator-(const Vec4 left, float right);
	friend Vec4 operator-(float right, const Vec4 left);
	friend Vec4 operator-(const Vec4 left, const Vec4 right);

	friend Vec4 operator*(const Vec4 left, float right);
	friend Vec4 operator*(float right, const Vec4 left);
	friend Vec4 operator*(const Vec4 left, const Vec4 right);

	friend Vec4 operator/(const Vec4 left, float right);
	friend Vec4 operator/(float right, const Vec4 left);
	friend Vec4 operator/(const Vec4 left, const Vec4 right);

	friend std::ostream& operator<<(std::ostream& ost, const Vec4& vector);

	static float magnitud(const Vec4& vector);
	static float dot(const Vec4& left, const Vec4& right);
	static Vec4 normalize(const Vec4& vector);
};