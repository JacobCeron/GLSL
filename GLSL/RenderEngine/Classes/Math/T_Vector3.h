#pragma once
#ifndef T_VECTOR3_H
#define T_VECTOR3_H

#include <ostream>

template<typename T>
struct T_Vector2;
template<typename T>
struct T_Vector4;

template<typename T>
struct T_Vector3
{
public:
	union
	{
		struct { T x, y, z; };
		struct { T r, g, b; };
	};
	static size_t size;
	
	static T_Vector3<T> right;
	static T_Vector3<T> up;
	static T_Vector3<T> forward;

public:
	T_Vector3();
	T_Vector3(T _x);
	T_Vector3(T _x, T _y, T _z);
	T_Vector3(const T_Vector2<T>& vector, T _z);
	T_Vector3(const T_Vector4<T>& vector);
	T_Vector3(const T_Vector3<T>& copy);

	const T_Vector3<T>& operator=(const T_Vector3<T>& vector);
	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	T_Vector3<T> operator-();
	T_Vector3<T>& operator++();
	const T_Vector3<T>& operator++(int);
	T_Vector3<T>& operator--();
	const T_Vector3<T>& operator--(int);

	template<typename T>
	friend bool operator==(const T_Vector3<T>& left, const T_Vector3<T>& right);
	template<typename T>
	friend bool operator!=(const T_Vector3<T>& left, const T_Vector3<T>& right);

	template<typename T>
	friend T_Vector3<T> operator+(const T_Vector3<T>& left, T right);
	template<typename T>
	friend T_Vector3<T> operator+(T right, const T_Vector3<T>& left);
	template<typename T>
	friend T_Vector3<T> operator+(const T_Vector3<T>& left, const T_Vector3<T>& right);

	template<typename T>
	friend T_Vector3<T> operator-(const T_Vector3<T>& left, T right);
	template<typename T>
	friend T_Vector3<T> operator-(T right, const T_Vector3<T>& left);
	template<typename T>
	friend T_Vector3<T> operator-(const T_Vector3<T>& left, const T_Vector3<T>& right);

	template<typename T>
	friend T_Vector3<T> operator*(const T_Vector3<T>& left, T right);
	template<typename T>
	friend T_Vector3<T> operator*(T right, const T_Vector3<T>& left);
	template<typename T>
	friend T_Vector3<T> operator*(const T_Vector3<T>& left, const T_Vector3<T>& right);

	template<typename T>
	friend T_Vector3<T> operator/(const T_Vector3<T>& left, T right);
	template<typename T>
	friend T_Vector3<T> operator/(T right, const T_Vector3<T>& left);
	template<typename T>
	friend T_Vector3<T> operator/(const T_Vector3<T>& left, const T_Vector3<T>& right);

	template<typename T>
	friend std::ostream& operator<<(std::ostream& ost, const T_Vector3<T>& vector);

	static T magnitud(const T_Vector3<T>& vector);
	static T dot(const T_Vector3<T>& left, const T_Vector3<T>& right);
	static T_Vector3<T> normalize(const T_Vector3<T>& vector);
	static T_Vector3<T> cross(const T_Vector3<T>& left, const T_Vector3<T>& right);
};

#endif

#include "T_Vector3.inl"