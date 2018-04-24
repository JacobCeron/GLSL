#ifdef T_VECTOR3_H

#include <assert.h>
#include <cmath>

template<typename T>
size_t T_Vector3<T>::size{ 3 };

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
T_Vector3<T>::T_Vector3(const T_Vector3<T>& copy)
	: x{ copy.x }, y{ copy.y }, z{ copy.z }
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

#endif