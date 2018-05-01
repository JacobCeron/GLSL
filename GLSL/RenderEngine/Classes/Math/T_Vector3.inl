#ifdef T_VECTOR3_H

#include <assert.h>
#include <cmath>

#include "T_Vector2.h"
#include "T_Vector4.h"

template<typename T>
size_t T_Vector3<T>::size{ 3 };

template<typename T>
T_Vector3<T> T_Vector3<T>::right(1, 0, 0);
template<typename T>
T_Vector3<T> T_Vector3<T>::up(0, 1, 0);
template<typename T>
T_Vector3<T> T_Vector3<T>::forward(0, 0, 1);

template<typename T>
T_Vector3<T>::T_Vector3()
	: x{ 0 }, y{ 0 }, z{ 0 }
{}

template<typename T>
T_Vector3<T>::T_Vector3(T _x)
	: x{ _x }, y{ _x }, z{ _x }
{}

template<typename T>
T_Vector3<T>::T_Vector3(T _x, T _y, T _z)
	: x{ _x }, y{ _y }, z{ _z }
{}

template<typename T>
T_Vector3<T>::T_Vector3(const T_Vector2<T>& vector, T _z)
	: T_Vector3(vector.x, vector.y, _z)
{}

template<typename T>
T_Vector3<T>::T_Vector3(const T_Vector4<T>& vector)
	: T_Vector3(vector.x, vector.y, vector.z)
{}

template<typename T>
T_Vector3<T>::T_Vector3(const T_Vector3<T>& copy)
	: T_Vector3(copy.x, copy.y, copy.z)
{}

template<typename T>
const T_Vector3<T>& T_Vector3<T>::operator=(const T_Vector3<T>& vector)
{
	assert(this != &vector);
	x = vector.x;
	y = vector.y;
	z = vector.z;

	return *this;
}

template<typename T>
T& T_Vector3<T>::operator[](size_t index)
{
	assert(index >= 0 && index < size);
	return (&x)[index];
}

template<typename T>
const T& T_Vector3<T>::operator[](size_t index) const
{
	assert(index >= 0 && index < size);
	return (&x)[index];
}

template<typename T>
T_Vector3<T> T_Vector3<T>::operator-()
{
	return T_Vector3<T>(-x, -y, -z);
}

template<typename T>
T_Vector3<T>& T_Vector3<T>::operator++()
{
	++x;
	++y;
	++z;
	return *this;
}

template<typename T>
const T_Vector3<T>& T_Vector3<T>::operator++(int)
{
	T_Vector3<T> temp(*this);
	x++;
	y++;
	z++;
	return temp;
}

template<typename T>
T_Vector3<T>& T_Vector3<T>::operator--()
{
	--x;
	--y;
	--z;
	return *this;
}

template<typename T>
const T_Vector3<T>& T_Vector3<T>::operator--(int)
{
	T_Vector3<T> temp(*this);
	x--;
	y--;
	z--;
	return temp;
}

template<typename T>
bool operator==(const T_Vector3<T>& left, const T_Vector3<T>& right)
{
	return (left.x == right.x && left.y == right.y && left.z == right.z);
}

template<typename T>
bool operator!=(const T_Vector3<T>& left, const T_Vector3<T>& right)
{
	return !(left == right);
}

template<typename T>
T_Vector3<T> operator+(const T_Vector3<T>& left, T right)
{
	return T_Vector3<T>
	(
		left.x + right,
		left.y + right,
		left.z + right
	);
}

template<typename T>
T_Vector3<T> operator+(T left, const T_Vector3<T>& right)
{
	return T_Vector3<T>
	(
		left + right.x,
		left + right.y,
		left + right.z
	);
}

template<typename T>
T_Vector3<T> operator+(const T_Vector3<T>& left, const T_Vector3<T>& right)
{
	return T_Vector3<T>
	(
		left.x + right.x,
		left.y + right.y,
		left.z + right.z
	);
}

template<typename T>
T_Vector3<T> operator-(const T_Vector3<T>& left, T right)
{
	return T_Vector3<T>
	(
		left.x - right,
		left.y - right,
		left.z - right
	);
}

template<typename T>
T_Vector3<T> operator-(T left, const T_Vector3<T>& right)
{
	return T_Vector3<T>
	(
		left - right.x,
		left - right.y,
		left - right.z
	);
}

template<typename T>
T_Vector3<T> operator-(const T_Vector3<T>& left, const T_Vector3<T>& right)
{
	return T_Vector3<T>
	(
		left.x - right.x,
		left.y - right.y,
		left.z - right.z
	);
}

template<typename T>
T_Vector3<T> operator*(const T_Vector3<T>& left, T right)
{
	return T_Vector3<T>
	(
		left.x * right,
		left.y * right,
		left.z * right
	);
}

template<typename T>
T_Vector3<T> operator*(T left, const T_Vector3<T>& right)
{
	return T_Vector3<T>
	(
		left * right.x,
		left * right.y,
		left * right.z
	);
}

template<typename T>
T_Vector3<T> operator*(const T_Vector3<T>& left, const T_Vector3<T>& right)
{
	return T_Vector3<T>
	(
		left.x * right.x,
		left.y * right.y,
		left.z * right.z
	);
}

template<typename T>
T_Vector3<T> operator/(const T_Vector3<T>& left, T right)
{
	return T_Vector3<T>
	(
		left.x / right,
		left.y / right,
		left.z / right
	);
}

template<typename T>
T_Vector3<T> operator/(T left, const T_Vector3<T>& right)
{
	return T_Vector3<T>
	(
		left / right.x,
		left / right.y,
		left / right.z
	);
}

template<typename T>
T_Vector3<T> operator/(const T_Vector3<T>& left, const T_Vector3<T>& right)
{
	return T_Vector3<T>
	(
		left.x / right.x,
		left.y / right.y,
		left.z / right.z
	);
}

template<typename T>
std::ostream& operator<<(std::ostream& ost, const T_Vector3<T>& vector)
{
	ost << vector.x << " " << vector.y << " " << vector.z;
	return ost;
}

template<typename T>
T T_Vector3<T>::magnitud(const T_Vector3<T>& vector)
{
	return sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

template<typename T>
T T_Vector3<T>::dot(const T_Vector3<T>& left, const T_Vector3<T>& right)
{
	return (left.x * right.x + left.y * right.y + left.z * right.z);
}

template<typename T>
T_Vector3<T> T_Vector3<T>::normalize(const T_Vector3<T>& vector)
{
	T length{ magnitud(vector) };
	return T_Vector3<T>(vector / length);
}

template<typename T>
inline T_Vector3<T> T_Vector3<T>::cross(const T_Vector3<T>& left, const T_Vector3<T>& right)
{
	return T_Vector3<T>
		(
			left.y * right.z - left.z * right.y,
			left.z * right.x - left.x * right.z,
			left.x * right.y - left.y * right.x
		);
}

#endif