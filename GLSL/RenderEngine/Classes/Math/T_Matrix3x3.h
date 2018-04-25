#pragma once
#ifndef T_MATRIX3X3_H
#define T_MATRIX3X3_H

#include <ostream>

#include "T_Vector3.h"
#include "T_Vector4.h"

template<typename T>
struct T_Matrix4x4;

template<typename T>
struct T_Matrix3x3
{
public:
	T_Vector3<T> data[3];
	static size_t rows;
private:


public:
	T_Matrix3x3();
	T_Matrix3x3(const T_Vector3<T>& v1, const T_Vector3<T>& v2, const T_Vector3<T>& v3);
	T_Matrix3x3(const T_Matrix4x4<T>& matrix);
	T_Matrix3x3(const T_Matrix3x3<T>& copy);

	const T_Matrix3x3<T>& operator=(const T_Matrix3x3<T>& matrix);
	T_Vector3<T>& operator[](size_t index);
	const T_Vector3<T>& operator[](size_t index) const;

	template<typename T>
	friend T_Matrix3x3<T> operator+(T left, const T_Matrix3x3<T>& right);
	template<typename T>
	friend T_Matrix3x3<T> operator+(const T_Matrix3x3<T>& left, T right);
	template<typename T>
	friend T_Matrix3x3<T> operator+(const T_Matrix3x3<T>& left, const T_Matrix3x3<T>& right);

	template<typename T>
	friend T_Matrix3x3<T> operator-(T left, const T_Matrix3x3<T>& right);
	template<typename T>
	friend T_Matrix3x3<T> operator-(const T_Matrix3x3<T>& left, T right);
	template<typename T>
	friend T_Matrix3x3<T> operator-(const T_Matrix3x3<T>& left, const T_Matrix3x3<T>& right);

	template<typename T>
	friend T_Matrix3x3<T> operator*(T left, const T_Matrix3x3<T>& right);
	template<typename T>
	friend T_Matrix3x3<T> operator*(const T_Matrix3x3<T>& left, T right);
	template<typename T>
	friend T_Vector3<T> operator*(const T_Vector3<T>& left, const T_Matrix3x3<T>& right);
	template<typename T>
	friend T_Vector3<T> operator*(const T_Matrix3x3<T>& left, const T_Vector3<T>& right);
	template<typename T>
	friend T_Matrix3x3<T> operator*(const T_Matrix3x3<T>& left, const T_Matrix3x3<T>& right);

	template<typename T>
	friend std::ostream& operator<<(std::ostream& ost, const T_Matrix3x3<T>& matrix);

	static T_Matrix3x3<T> transpose(const T_Matrix3x3<T>& matrix);
	static T_Matrix3x3<T> inverse(const T_Matrix3x3<T>& matrix);
	static T_Matrix3x3<T> translate(const T_Matrix3x3<T>& matrix, const T_Vector3<T>& vector);
	static T_Matrix3x3<T> scale(const T_Matrix3x3<T>& matrix, const T_Vector3<T>& vector);
	static T_Matrix3x3<T> rotate(const T_Matrix3x3<T>& matrix, float angle, const T_Vector3<T>& axis);
};

#endif

#include "T_Matrix3x3.inl"