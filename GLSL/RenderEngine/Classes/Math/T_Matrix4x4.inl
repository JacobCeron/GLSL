#ifdef T_MATRIX4X4_H

#include <cassert>

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
T_Matrix4x4<T>::T_Matrix4x4(const T_Matrix4x4<T>& copy)
{
	for (size_t i{ 0 }; i < rows; i++)
		data[i] = copy[i];
}

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
	T_Matrix4x4<T> R;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		R[i] = left + right[i];
	return R;
}

template<typename T>
T_Matrix4x4<T> operator+(const T_Matrix4x4<T>& left, T right)
{
	return right + left;
}

template<typename T>
T_Matrix4x4<T> operator+(const T_Matrix4x4<T>& left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> R;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		R[i] = left[i] + right[i];
	return R;
}

template<typename T>
T_Matrix4x4<T> operator-(T left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> R;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		R[i] = left - right[i];
	return R;
}

template<typename T>
T_Matrix4x4<T> operator-(const T_Matrix4x4<T>& left, T right)
{
	T_Matrix4x4<T> R;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		R[i] = left[i] - right;
	return R;
}

template<typename T>
T_Matrix4x4<T> operator-(const T_Matrix4x4<T>& left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> R;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		R[i] = left[i] - right[i];
	return R;
}

template<typename T>
T_Matrix4x4<T> operator*(T left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> R;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		R[i] = left * right[i];
	return R;
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
		Result[0][i] = T_Vector4<T>::dot(temp, right[i]);
		Result[1][i] = T_Vector4<T>::dot(temp, right[i]);
		Result[2][i] = T_Vector4<T>::dot(temp, right[i]);
		Result[3][i] = T_Vector4<T>::dot(temp, right[i]);
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
T_Matrix4x4<T> T_Matrix4x4<T>::translate(const T_Matrix4x4<T>& matrix, const T_Vector3<T>& vector)
{
	T_Matrix4x4<T> R(matrix);
	R[3].x += vector.x;
	R[3].y += vector.y;
	R[3].z += vector.z;
	return R;
}

template<typename T>
T_Matrix4x4<T> T_Matrix4x4<T>::scale(const T_Matrix4x4<T>& matrix, const T_Vector3<T>& vector)
{
	T_Matrix4x4<T> R(matrix);
	R[0].x *= vector.x;
	R[1].y *= vector.y;
	R[2].z *= vector.z;
	return R;
}

template<typename T>
T_Matrix4x4<T> T_Matrix4x4<T>::rotate(const T_Matrix4x4<T>& matrix, float angle, const T_Vector3<T>& axis)
{
	T_Matrix4x4<T> Rotate;

	const T cosT{ cos(angle) };
	const T sinT{ sin(angle) };

	T_Vector3<T>::normalize(axis);

	Rotate[0][0] = cosT + (axis.x * axis.x) * (1 - cosT);
	Rotate[1][0] = (axis.x * axis.y) * (1 - cosT) - axis.z * sinT;
	Rotate[2][0] = (axis.x * axis.z) * (1 - cosT) + axis.y * sinT;

	Rotate[0][1] = (axis.y * axis.x) * (1 - cosT) + axis.z * sinT;
	Rotate[1][1] = cosT + (axis.y * axis.y) * (1 - cosT);
	Rotate[2][1] = (axis.y * axis.z) * (1 - cosT) - axis.x * sinT;

	Rotate[0][2] = (axis.z * axis.x) * (1 - cosT) - axis.y * sinT;
	Rotate[1][2] = (axis.z * axis.y) * (1 - cosT) + axis.x * sinT;
	Rotate[2][2] = cosT + (axis.y * axis.y) * (1 - cosT);

	T_Matrix4x4<T> Result;
	Result[0] = matrix[0] * Rotate;
	Result[1] = matrix[1] * Rotate;
	Result[2] = matrix[2] * Rotate;
	Result[3] = matrix[3] * Rotate;

	return Result;
}

#endif