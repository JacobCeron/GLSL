#pragma once
#ifndef T_MATRIX4X4_H
#define T_MATRIX4X4_H

#include <ostream>

#include "T_Vector3.h"
#include "T_Vector4.h"

template<typename T>
struct T_Matrix4x4
{
public:
	T_Vector4<T> data[4];
	static size_t rows;
private:
	

public:
	T_Matrix4x4();
	T_Matrix4x4(const T_Vector4<T>& v1, const T_Vector4<T>& v2, const T_Vector4<T>& v3, const T_Vector4<T>& v4);
	T_Matrix4x4(const T_Matrix4x4<T>& copy);

	const T_Matrix4x4<T>& operator=(const T_Matrix4x4<T>& matrix);
	T_Vector4<T>& operator[](size_t index);
	const T_Vector4<T>& operator[](size_t index) const;

	template<typename T>
	friend T_Matrix4x4<T> operator+(T left, const T_Matrix4x4<T>& right);
	template<typename T>
	friend T_Matrix4x4<T> operator+(const T_Matrix4x4<T>& left, T right);
	template<typename T>
	friend T_Matrix4x4<T> operator+(const T_Matrix4x4<T>& left, const T_Matrix4x4<T>& right);

	template<typename T>
	friend T_Matrix4x4<T> operator-(T left, const T_Matrix4x4<T>& right);
	template<typename T>
	friend T_Matrix4x4<T> operator-(const T_Matrix4x4<T>& left, T right);
	template<typename T>
	friend T_Matrix4x4<T> operator-(const T_Matrix4x4<T>& left, const T_Matrix4x4<T>& right);

	template<typename T>
	friend T_Matrix4x4<T> operator*(T left, const T_Matrix4x4<T>& right);
	template<typename T>
	friend T_Matrix4x4<T> operator*(const T_Matrix4x4<T>& left, T right);
	template<typename T>
	friend T_Vector4<T> operator*(const T_Vector4<T>& left, const T_Matrix4x4<T>& right);
	template<typename T>
	friend T_Vector4<T> operator*(const T_Matrix4x4<T>& left, const T_Vector4<T>& right);
	template<typename T>
	friend T_Matrix4x4<T> operator*(const T_Matrix4x4<T>& left, const T_Matrix4x4<T>& right);

	template<typename T>
	friend std::ostream& operator<<(std::ostream& ost, const T_Matrix4x4<T>& matrix);

	static T_Matrix4x4<T> transpose(const T_Matrix4x4<T>& matrix);
	static T_Matrix4x4<T> translate(const T_Matrix4x4<T>& matrix, const T_Vector3<T>& vector);
	static T_Matrix4x4<T> scale(const T_Matrix4x4<T>& matrix, const T_Vector3<T>& vector);
	static T_Matrix4x4<T> rotate(const T_Matrix4x4<T>& matrix, float angle, const T_Vector3<T>& axis);
	static T_Matrix4x4<T> lookAt(const T_Vector3<T>& eye, const T_Vector3<T>& target, const T_Vector3<T>& up);
	static T_Matrix4x4<T> ortho(T left, T right, T bottom, T top, T near, T far);
};

#endif

#include "T_Matrix4x4.inl"