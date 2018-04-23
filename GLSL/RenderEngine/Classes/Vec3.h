#pragma once

#include <ostream>

struct Vec3
{
public:
	union
	{
		struct { float x, y, z; };
		struct { float r, g, b; };
	};
	static size_t size;

public:
	Vec3();
	Vec3(float _x);
	Vec3(float _x, float _y, float _z);
	Vec3(const Vec3& copy);

	const Vec3& operator=(const Vec3& vector);
	float& operator[](size_t index);
	const float& operator[](size_t index) const;

	Vec3 operator-();
	Vec3& operator++();
	const Vec3& operator++(int);
	Vec3& operator--();
	const Vec3& operator--(int);

	friend Vec3 operator+(const Vec3 left, float right);
	friend Vec3 operator+(float right, const Vec3 left);
	friend Vec3 operator+(const Vec3 left, const Vec3 right);

	friend Vec3 operator-(const Vec3 left, float right);
	friend Vec3 operator-(float right, const Vec3 left);
	friend Vec3 operator-(const Vec3 left, const Vec3 right);

	friend Vec3 operator*(const Vec3 left, float right);
	friend Vec3 operator*(float right, const Vec3 left);
	friend Vec3 operator*(const Vec3 left, const Vec3 right);

	friend Vec3 operator/(const Vec3 left, float right);
	friend Vec3 operator/(float right, const Vec3 left);
	friend Vec3 operator/(const Vec3 left, const Vec3 right);

	friend std::ostream& operator<<(std::ostream& ost, const Vec3& vector);

	static float magnitud(const Vec3& vector);
	static float dot(const Vec3& left, const Vec3& right);
	static Vec3 normalize(const Vec3& vector);
};