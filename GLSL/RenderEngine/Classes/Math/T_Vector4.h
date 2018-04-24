#pragma once
#ifndef T_VECTOR4_H
#define T_VECTOR4_H

#include <ostream>

template<typename T>
struct T_Vector4
{
public:
	union
	{
		struct { T x, y, z, w; };
		struct { T r, g, b, a; };
	};
	static size_t size;

public:
	T_Vector4();
	T_Vector4(T _x);
	T_Vector4(T _x, T _y, T _z, T _w);
	T_Vector4(const T_Vector4<T>& copy);

	const T_Vector4<T>& operator=(const T_Vector4<T>& Vectortor);
	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	T_Vector4<T> operator-();
	T_Vector4<T>& operator++();
	const T_Vector4<T>& operator++(int);
	T_Vector4<T>& operator--();
	const T_Vector4<T>& operator--(int);

	template<typename T>
	friend T_Vector4<T> operator+(const T_Vector4<T>& left, T right);
	template<typename T>
	friend T_Vector4<T> operator+(T right, const T_Vector4<T>& left);
	template<typename T>
	friend T_Vector4<T> operator+(const T_Vector4<T>& left, const T_Vector4<T>& right);

	template<typename T>
	friend T_Vector4<T> operator-(const T_Vector4<T>& left, T right);
	template<typename T>
	friend T_Vector4<T> operator-(T right, const T_Vector4<T>& left);
	template<typename T>
	friend T_Vector4<T> operator-(const T_Vector4<T>& left, const T_Vector4<T>& right);

	template<typename T>
	friend T_Vector4<T> operator*(const T_Vector4<T>& left, T right);
	template<typename T>
	friend T_Vector4<T> operator*(T right, const T_Vector4<T>& left);
	template<typename T>
	friend T_Vector4<T> operator*(const T_Vector4<T>& left, const T_Vector4<T>& right);

	template<typename T>
	friend T_Vector4<T> operator/(const T_Vector4<T>& left, T right);
	template<typename T>
	friend T_Vector4<T> operator/(T right, const T_Vector4<T>& left);
	template<typename T>
	friend T_Vector4<T> operator/(const T_Vector4<T>& left, const T_Vector4<T>& right);

	template<typename T>
	friend std::ostream& operator<<(std::ostream& ost, const T_Vector4<T>& Vectortor);

	static T magnitud(const T_Vector4<T>& Vectortor);
	static T dot(const T_Vector4<T>& left, const T_Vector4<T>& right);
	static T_Vector4<T> normalize(const T_Vector4<T>& Vectortor);
};

#endif

#include "T_Vector4.inl"