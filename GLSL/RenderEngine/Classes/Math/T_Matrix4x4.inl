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
T_Matrix4x4<T> operator*(const T_Matrix4x4<T>& left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> R;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		R[i] = left[i] * right[i];
	return R;
}

template<typename T>
T_Matrix4x4<T> operator/(T left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> R;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		R[i] = left / right[i];
	return R;
}

template<typename T>
T_Matrix4x4<T> operator/(const T_Matrix4x4<T>& left, const T_Matrix4x4<T>& right)
{
	T_Matrix4x4<T> R;
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		R[i] = left[i] / right[i];
	return R;
}

template<typename T>
std::ostream& operator<<(std::ostream& ost, const T_Matrix4x4<T>& matrix)
{
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		ost << matrix[i] << "\n";
	return ost;
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

#endif