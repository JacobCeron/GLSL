#ifdef T_MATRIX4X4_H

#include <cassert>

#include "T_Matrix3x3.h"

template<typename T>
size_t T_Matrix4x4<T>::rows{ 4 };

template<typename T>
T_Matrix4x4<T>::T_Matrix4x4()
{
	for (size_t i{ 0 }; i < rows; i++)
		data[i][i] = 1;
}

template<typename T>
T_Matrix4x4<T>::T_Matrix4x4(const T_Vector4<T>& v1, const T_Vector4<T>& v2, const T_Vector4<T>& v3, const T_Vector4<T>& v4)
{
	data[0] = v1;
	data[1] = v2;
	data[2] = v3;
	data[3] = v4;
}

template<typename T>
T_Matrix4x4<T>::T_Matrix4x4(const T_Matrix3x3<T>& matrix, const T_Vector4<T>& vector)
	: T_Matrix4x4(matrix[0], matrix[1], matrix[2], vector)
{
}

template<typename T>
T_Matrix4x4<T>::T_Matrix4x4(const T_Matrix4x4<T>& copy)
	: T_Matrix4x4(copy[0], copy[1], copy[2], copy[3])
{}

template<typename T>
const T_Matrix4x4<T>& T_Matrix4x4<T>::operator=(const T_Matrix4x4<T>& matrix)
{
	assert(&matrix != this);
	for (size_t i{ 0 }; i < rows; i++)
		data[i] = matrix[i];

	return *this;
}

template<typename T>
T_Vector4<T>& T_Matrix4x4<T>::operator[](size_t index)
{
	assert(index >= 0 && index < rows);
	return data[index];
}

template<typename T>
const T_Vector4<T>& T_Matrix4x4<T>::operator[](size_t index) const
{
	assert(index >= 0 && index < rows);
	return data[index];
}

template<typename T>
T_Matrix4x4<T> operator+(T left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> Result;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		Result[i] = left + right[i];
	return Result;
}

template<typename T>
T_Matrix4x4<T> operator+(const T_Matrix4x4<T>& left, T right)
{
	return right + left;
}

template<typename T>
T_Matrix4x4<T> operator+(const T_Matrix4x4<T>& left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> Result;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		Result[i] = left[i] + right[i];
	return Result;
}

template<typename T>
T_Matrix4x4<T> operator-(T left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> Result;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		Result[i] = left - right[i];
	return Result;
}

template<typename T>
T_Matrix4x4<T> operator-(const T_Matrix4x4<T>& left, T right)
{
	T_Matrix4x4<T> Result;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		Result[i] = left[i] - right;
	return Result;
}

template<typename T>
T_Matrix4x4<T> operator-(const T_Matrix4x4<T>& left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> Result;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		Result[i] = left[i] - right[i];
	return Result;
}

template<typename T>
T_Matrix4x4<T> operator*(T left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> Result;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		Result[i] = left * right[i];
	return Result;
}

template<typename T>
T_Matrix4x4<T> operator*(const T_Matrix4x4<T>& left, T right)
{
	return right * left;
}

template<typename T>
T_Vector4<T> operator*(const T_Vector4<T>& left, const T_Matrix4x4<T>& right)
{
	T_Vector4<T> Result;
	Result[0] = T_Vector4<T>::dot(left, right[0]);
	Result[1] = T_Vector4<T>::dot(left, right[1]);
	Result[2] = T_Vector4<T>::dot(left, right[2]);
	Result[3] = T_Vector4<T>::dot(left, right[3]);

	return Result;
}

template<typename T>
T_Vector4<T> operator*(const T_Matrix4x4<T>& left, const T_Vector4<T>& right)
{
	return right * left;
}

template<typename T>
T_Matrix4x4<T> operator*(const T_Matrix4x4<T>& left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> Result;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
	{
		T_Vector4<T> temp(left[0][i], left[1][i], left[2][i], left[3][i]);
		Result[0][i] = T_Vector4<T>::dot(temp, right[0]);
		Result[1][i] = T_Vector4<T>::dot(temp, right[1]);
		Result[2][i] = T_Vector4<T>::dot(temp, right[2]);
		Result[3][i] = T_Vector4<T>::dot(temp, right[3]);
	}
	return Result;
}

template<typename T>
std::ostream& operator<<(std::ostream& ost, const T_Matrix4x4<T>& matrix)
{
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		ost << matrix[i] << "\n";
	return ost;
}

template<typename T>
T_Matrix4x4<T> T_Matrix4x4<T>::transpose(const T_Matrix4x4<T>& matrix)
{
	return T_Matrix4x4<T>
		(
			T_Vector4<T>(matrix[0][0], matrix[1][0], matrix[2][0], matrix[3][0]),
			T_Vector4<T>(matrix[0][1], matrix[1][1], matrix[2][1], matrix[3][1]),
			T_Vector4<T>(matrix[0][2], matrix[1][2], matrix[2][2], matrix[3][2]),
			T_Vector4<T>(matrix[0][3], matrix[1][3], matrix[2][3], matrix[3][3])
		);
}

template<typename T>
T_Matrix4x4<T> T_Matrix4x4<T>::inverse(const T_Matrix4x4<T>& matrix)
{
	return T_Matrix4x4<T>();
}

template<typename T>
T_Matrix4x4<T> T_Matrix4x4<T>::translate(const T_Matrix4x4<T>& matrix, const T_Vector3<T>& vector)
{
	T_Matrix4x4<T> Result(matrix);
	Result[3].x += vector.x;
	Result[3].y += vector.y;
	Result[3].z += vector.z;
	return Result;
}

template<typename T>
T_Matrix4x4<T> T_Matrix4x4<T>::scale(const T_Matrix4x4<T>& matrix, const T_Vector3<T>& vector)
{
	T_Matrix4x4<T> Result(matrix);
	Result[0].x *= vector.x;
	Result[1].y *= vector.y;
	Result[2].z *= vector.z;
	return Result;
}

template<typename T>
T_Matrix4x4<T> T_Matrix4x4<T>::rotate(const T_Matrix4x4<T>& matrix, float angle, const T_Vector3<T>& axis)
{
	T_Matrix4x4<T> Rotate;

	const T cosT{ cos(angle) };
	const T sinT{ sin(angle) };

	T_Vector3<T> u = T_Vector3<T>::normalize(axis);

	Rotate[0][0] = cosT + (u.x * u.x) * (1 - cosT);
	Rotate[0][1] = (u.x * u.y) * (1 - cosT) - u.z * sinT;
	Rotate[0][2] = (u.x * u.z) * (1 - cosT) + u.y * sinT;

	Rotate[1][0] = (u.y * u.x) * (1 - cosT) + u.z * sinT;
	Rotate[1][1] = cosT + (u.y * u.y) * (1 - cosT);
	Rotate[1][2] = (u.y * u.z) * (1 - cosT) - u.x * sinT;

	Rotate[2][0] = (u.z * u.x) * (1 - cosT) - u.y * sinT;
	Rotate[2][1] = (u.z * u.y) * (1 - cosT) + u.x * sinT;
	Rotate[2][2] = cosT + (u.z * u.z) * (1 - cosT);

	T_Matrix4x4<T> Result;
	Result[0] = matrix[0] * Rotate[0][0] + matrix[1] * Rotate[1][0] + matrix[2] * Rotate[2][0];
	Result[1] = matrix[0] * Rotate[0][1] + matrix[1] * Rotate[1][1] + matrix[2] * Rotate[2][1];
	Result[2] = matrix[0] * Rotate[0][2] + matrix[1] * Rotate[1][2] + matrix[2] * Rotate[2][2];
	Result[3] = matrix[3];

	return Result;
}

template<typename T>
T_Matrix4x4<T> T_Matrix4x4<T>::lookAt(const T_Vector3<T>& eye, const T_Vector3<T>& target, const T_Vector3<T>& up)
{
	T_Vector3<T> zAxis(T_Vector3<T>::normalize(eye - target));
	T_Vector3<T> xAxis(T_Vector3<T>::normalize(T_Vector3<T>::cross(up, zAxis)));
	T_Vector3<T> yAxis(T_Vector3<T>::cross(zAxis, xAxis));

	T_Matrix4x4<T> Rotate;
	Rotate[0][0] = xAxis.x;
	Rotate[1][0] = xAxis.y;
	Rotate[2][0] = xAxis.z;
	
	Rotate[0][1] = yAxis.x;
	Rotate[1][1] = yAxis.y;
	Rotate[2][1] = yAxis.z;

	Rotate[0][2] = zAxis.x;
	Rotate[1][2] = zAxis.y;
	Rotate[2][2] = zAxis.z;

	T_Matrix4x4<T> Translate;
	Translate[3][0] = -eye.x;
	Translate[3][1] = -eye.y;
	Translate[3][2] = -eye.z;

	return Rotate * Translate;
}

template<typename T>
T_Matrix4x4<T> T_Matrix4x4<T>::ortho(T left, T right, T bottom, T top, T front, T back)
{
	T_Matrix4x4<T> Result;
	Result[0][0] = 2.0f / (right - left);
	Result[1][1] = 2.0f / (top - bottom);
	Result[2][2] = 2.0f / (front - back);
	Result[3][0] = -(right + left) / (right - left);
	Result[3][1] = -(top + bottom) / (top - bottom);
	Result[3][2] = -(back + front) / (back - front);

	return Result;
}

#endif