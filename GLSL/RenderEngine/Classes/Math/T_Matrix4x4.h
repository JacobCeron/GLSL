#pragma once
#ifndef T_MATRIX4X4_H
#define T_MATRIX4X4_H

#include <ostream>

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
	T_Matrix4x4(const T_Matrix4x4<T>& copy);

	const T_Matrix4x4<T>& operator=(const T_Matrix4x4<T>& matrix);
	T_Vector4<T>& operator[](size_t index);
	const T_Vector4<T>& operator[](size_t index) const;

	template<typename T>
	friend std::ostream& operator<<(std::ostream& ost, const T_Matrix4x4<T>& matrix);
};

#endif

#include "T_Matrix4x4.inl"