#ifdef T_VECTOR2_H

#include <assert.h>
#include <cmath>

template<typename T>
size_t T_Vector2<T>::size{ 2 };

template<typename T>
T_Vector2<T>::T_Vector2()
	: x{ 0 }, y{ 0 }
{}

template<typename T>
T_Vector2<T>::T_Vector2(T _x)
	: x{ _x }, y{ _x }
{}

template<typename T>
T_Vector2<T>::T_Vector2(T _x, T _y)
	: x{ _x }, y{ _y }
{}

template<typename T>
T_Vector2<T>::T_Vector2(const T_Vector2<T>& copy)
	: x{ copy.x }, y{ copy.y }
{}

template<typename T>
const T_Vector2<T>& T_Vector2<T>::operator=(const T_Vector2<T>& vector)
{
	assert(this != &vector);
	x = vector.x;
	y = vector.y;

	return *this;
}

template<typename T>
T& T_Vector2<T>::operator[](size_t index)
{
	assert(index >= 0 && index < size);
	return (&x)[index];
}

template<typename T>
const T& T_Vector2<T>::operator[](size_t index) const
{
	assert(index >= 0 && index < size);
	return (&x)[index];
}

template<typename T>
T_Vector2<T> T_Vector2<T>::operator-()
{
	return T_Vector2<T>(-x, -y);
}

template<typename T>
T_Vector2<T>& T_Vector2<T>::operator++()
{
	++x;
	++y;
	return *this;
}

template<typename T>
const T_Vector2<T>& T_Vector2<T>::operator++(int)
{
	T_Vector2<T> temp(*this);
	x++;
	y++;
	return temp;
}

template<typename T>
T_Vector2<T>& T_Vector2<T>::operator--()
{
	--x;
	--y;
	return *this;
}

template<typename T>
const T_Vector2<T>& T_Vector2<T>::operator--(int)
{
	T_Vector2 temp(*this);
	x--;
	y--;
	return temp;
}

template<typename T>
T_Vector2<T> operator+(const T_Vector2<T>& left, T right)
{
	return T_Vector2<T>
	(
		left.x + right,
		left.y + right
	);
}

template<typename T>
T_Vector2<T> operator+(T left, const T_Vector2<T>& right)
{
	return T_Vector2<T>
	(
		left + right.x,
		left + right.y
	);
}

template<typename T>
T_Vector2<T> operator+(const T_Vector2<T>& left, const T_Vector2<T>& right)
{
	return T_Vector2<T>
	(
		left.x + right.x,
		left.y + right.y
	);
}

template<typename T>
T_Vector2<T> operator-(const T_Vector2<T>& left, T right)
{
	return T_Vector2<T>
	(
		left.x - right,
		left.y - right
	);
}

template<typename T>
T_Vector2<T> operator-(T left, const T_Vector2<T>& right)
{
	return T_Vector2
	(
		left - right.x,
		left - right.y
	);
}

template<typename T>
T_Vector2<T> operator-(const T_Vector2<T>& left, const T_Vector2<T>& right)
{
	return T_Vector2<T>
	(
		left.x - right.x,
		left.y - right.y
	);
}

template<typename T>
T_Vector2<T> operator*(const T_Vector2<T>& left, T right)
{
	return T_Vector2<T>
	(
		left.x * right,
		left.y * right
	);
}

template<typename T>
T_Vector2<T> operator*(T left, const T_Vector2<T>& right)
{
	return T_Vector2<T>
	(
		left * right.x,
		left * right.y
	);
}

template<typename T>
T_Vector2<T> operator*(const T_Vector2<T>& left, const T_Vector2<T>& right)
{
	return T_Vector2
	(
		left.x * right.x,
		left.y * right.y
	);
}

template<typename T>
T_Vector2<T> operator/(const T_Vector2<T>& left, T right)
{
	return T_Vector2<T>
	(
		left.x / right,
		left.y / right
	);
}

template<typename T>
T_Vector2<T> operator/(T left, const T_Vector2<T>& right)
{
	return T_Vector2<T>
	(
		left / right.x,
		left / right.y
	);
}

template<typename T>
T_Vector2<T> operator/(const T_Vector2<T>& left, const T_Vector2<T>& right)
{
	return T_Vector2<T>
	(
		left.x / right.x,
		left.y / right.y
	);
}

template<typename T>
std::ostream& operator<<(std::ostream & ost, const T_Vector2<T> & vector)
{
	ost << vector.x << " " << vector.y;
	return ost;
}

template<typename T>
T T_Vector2<T>::magnitud(const T_Vector2<T>& vector)
{
	return sqrtf( vector.x * vector.x + vector.y * vector.y );
}

template<typename T>
T T_Vector2<T>::dot(const T_Vector2& left, const T_Vector2& right)
{
	return (left.x * right.x + left.y * right.y);
}

template<typename T>
T_Vector2<T> T_Vector2<T>::normalize(const T_Vector2<T>& vector)
{
	T length{ magnitud(vector) };
	return T_Vector2(vector / length);
}

#endif