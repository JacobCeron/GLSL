#pragma once
#ifndef T_VECTOR2_H
#define T_VECTOR2_H

#include <ostream>

template<typename T>
struct T_Vector3;
template<typename T>
struct T_Vector4;

template<typename T>
struct T_Vector2
{
public:
	union
	{
		struct { T x, y; };
		struct { T r, g; };
	};
	static size_t size;

public:
	T_Vector2();
	T_Vector2(T _x);
	T_Vector2(T _x, T _y);
	T_Vector2(const T_Vector3<T>& vector);
	T_Vector2(const T_Vector4<T>& vector);
	T_Vector2(const T_Vector2<T>& copy);

	const T_Vector2<T>& operator=(const T_Vector2<T>& vector);
	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	T_Vector2<T> operator-();
	T_Vector2<T>& operator++();
	const T_Vector2<T>& operator++(int);
	T_Vector2<T>& operator--();
	const T_Vector2<T>& operator--(int);

	template<typename T>
	friend T_Vector2<T> operator+(const T_Vector2<T>& left, T right);
	template<typename T>
	friend T_Vector2<T> operator+(T right, const T_Vector2<T>& left);
	template<typename T>
	friend T_Vector2<T> operator+(const T_Vector2<T>& left, const T_Vector2<T>& right);

	template<typename T>
	friend T_Vector2<T> operator-(const T_Vector2<T>& left, T right);
	template<typename T>
	friend T_Vector2<T> operator-(T right, const T_Vector2<T>& left);
	template<typename T>
	friend T_Vector2<T> operator-(const T_Vector2<T>& left, const T_Vector2<T>& right);

	template<typename T>
	friend T_Vector2<T> operator*(const T_Vector2<T>& left, T right);
	template<typename T>
	friend T_Vector2<T> operator*(T right, const T_Vector2<T>& left);
	template<typename T>
	friend T_Vector2<T> operator*(const T_Vector2<T>& left, const T_Vector2<T>& right);

	template<typename T>
	friend T_Vector2<T> operator/(const T_Vector2<T>& left, T right);
	template<typename T>
	friend T_Vector2<T> operator/(T right, const T_Vector2<T>& left);
	template<typename T>
	friend T_Vector2<T> operator/(const T_Vector2<T>& left, const T_Vector2<T>& right);

	template<typename T>
	friend std::ostream& operator<<(std::ostream& ost, const T_Vector2<T>& vector);

	static T magnitud(const T_Vector2<T>& vector);
	static T dot(const T_Vector2<T>& left, const T_Vector2<T>& right);
	static T_Vector2<T> normalize(const T_Vector2<T>& vector);
};

#endif

#include "T_Vector2.inl"