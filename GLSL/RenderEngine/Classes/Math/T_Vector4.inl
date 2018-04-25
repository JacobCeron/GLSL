#ifdef T_VECTOR4_H

#include <assert.h>
#include <cmath>

#include "T_Vector2.h"
#include "T_Vector3.h"

template<typename T>
size_t T_Vector4<T>::size{ 4 };

template<typename T>
T_Vector4<T>::T_Vector4()
	: x{ 0 }, y{ 0 }, z{ 0 }, w{ 0 }
{}

template<typename T>
T_Vector4<T>::T_Vector4(T _x)
	: x{ _x }, y{ _x }, z{ _x }, w{ _x }
{}

template<typename T>
T_Vector4<T>::T_Vector4(T _x, T _y, T _z, T _w)
	: x{ _x }, y{ _y }, z{ _z }, w{ _w }
{}

template<typename T>
T_Vector4<T>::T_Vector4(const T_Vector2<T>& vector, T _z, T _w)
	: T_Vector4(vector.x, vector.y, _z, _w)
{}

template<typename T>
T_Vector4<T>::T_Vector4(const T_Vector3<T>& vector, T _w)
	: T_Vector4(vector.x, vector.y, vector.z, _w)
{}

template<typename T>
T_Vector4<T>::T_Vector4(const T_Vector4<T>& copy)
	: T_Vector4(copy.x, copy.y, copy.z, copy.w)
{}

template<typename T>
const T_Vector4<T>& T_Vector4<T>::operator=(const T_Vector4<T>& vector)
{
	assert(this != &vector);
	x = vector.x;
	y = vector.y;
	z = vector.z;
	w = vector.w;

	return *this;
}

template<typename T>
T& T_Vector4<T>::operator[](size_t index)
{
	assert(index >= 0 && index < size);
	return (&x)[index];
}

template<typename T>
const T& T_Vector4<T>::operator[](size_t index) const
{
	assert(index >= 0 && index < size);
	return (&x)[index];
}

template<typename T>
T_Vector4<T> T_Vector4<T>::operator-()
{
	return T_Vector4<T>(-x, -y, -z, -w);
}

template<typename T>
T_Vector4<T>& T_Vector4<T>::operator++()
{
	++x;
	++y;
	++z;
	++w;
	return *this;
}

template<typename T>
const T_Vector4<T>& T_Vector4<T>::operator++(int)
{
	T_Vector4<T> temp(*this);
	x++;
	y++;
	z++;
	w++;
	return temp;
}

template<typename T>
T_Vector4<T>& T_Vector4<T>::operator--()
{
	--x;
	--y;
	--z;
	--w;
	return *this;
}

template<typename T>
const T_Vector4<T>& T_Vector4<T>::operator--(int)
{
	T_Vector4<T> temp(*this);
	x--;
	y--;
	z--;
	w--;
	return temp;
}

template<typename T>
T_Vector4<T> operator+(const T_Vector4<T>& left, T right)
{
	return T_Vector4<T>
	(
		left.x + right,
		left.y + right,
		left.z + right,
		left.w + right
	);
}

template<typename T>
T_Vector4<T> operator+(T left, const T_Vector4<T>& right)
{
	return T_Vector4<T>
	(
		left + right.x,
		left + right.y,
		left + right.z,
		left + right.w
	);
}

template<typename T>
T_Vector4<T> operator+(const T_Vector4<T>& left, const T_Vector4<T>& right)
{
	return T_Vector4<T>
	(
		left.x + right.x,
		left.y + right.y,
		left.z + right.z,
		left.w + right.w
	);
}

template<typename T>
T_Vector4<T> operator-(const T_Vector4<T>& left, T right)
{
	return T_Vector4<T>
	(
		left.x - right,
		left.y - right,
		left.z - right,
		left.w - right
	);
}

template<typename T>
T_Vector4<T> operator-(T left, const T_Vector4<T>& right)
{
	return T_Vector4<T>
	(
		left - right.x,
		left - right.y,
		left - right.z,
		left - right.w
	);
}

template<typename T>
T_Vector4<T> operator-(const T_Vector4<T>& left, const T_Vector4<T>& right)
{
	return T_Vector4<T>
	(
		left.x - right.x,
		left.y - right.y,
		left.z - right.z,
		left.w - right.w
	);
}

template<typename T>
T_Vector4<T> operator*(const T_Vector4<T>& left, T right)
{
	return T_Vector4<T>
	(
		left.x * right,
		left.y * right,
		left.z * right,
		left.w * right
	);
}

template<typename T>
T_Vector4<T> operator*(T left, const T_Vector4<T>& right)
{
	return T_Vector4<T>
	(
		left * right.x,
		left * right.y,
		left * right.z,
		left * right.w
	);
}

template<typename T>
T_Vector4<T> operator*(const T_Vector4<T>& left, const T_Vector4<T>& right)
{
	return T_Vector4<T>
	(
		left.x * right.x,
		left.y * right.y,
		left.z * right.z,
		left.w * right.w
	);
}

template<typename T>
T_Vector4<T> operator/(const T_Vector4<T>& left, T right)
{
	return T_Vector4<T>
	(
		left.x / right,
		left.y / right,
		left.z / right,
		left.w / right
	);
}

template<typename T>
T_Vector4<T> operator/(T left, const T_Vector4<T>& right)
{
	return T_Vector4<T>
	(
		left / right.x,
		left / right.y,
		left / right.z,
		left / right.w
	);
}

template<typename T>
T_Vector4<T> operator/(const T_Vector4<T>& left, const T_Vector4<T>& right)
{
	return T_Vector4<T>
	(
		left.x / right.x,
		left.y / right.y,
		left.z / right.z,
		left.w / right.w
	);
}

template<typename T>
std::ostream& operator<<(std::ostream& ost, const T_Vector4<T>& vector)
{
	ost << vector.x << " " << vector.y << " " << vector.z << " " << vector.w;
	return ost;
}

template<typename T>
T T_Vector4<T>::magnitud(const T_Vector4<T>& vector)
{
	return sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w);
}

template<typename T>
T T_Vector4<T>::dot(const T_Vector4<T>& left, const T_Vector4<T>& right)
{
	return (left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w);
}

template<typename T>
T_Vector4<T> T_Vector4<T>::normalize(const T_Vector4<T>& vector)
{
	T length{ magnitud(vector) };
	return T_Vector4<T>(vector / length);
}

#endif