#ifdef T_MATRIX3X3_H

#include <cassert>

template<typename T>
size_t T_Matrix3x3<T>::rows{ 3 };

template<typename T>
T_Matrix3x3<T>::T_Matrix3x3()
{
	for (size_t i{ 0 }; i < rows; i++)
		data[i][i] = 1;
}

template<typename T>
T_Matrix3x3<T>::T_Matrix3x3(const T_Matrix3x3<T>& copy)
{
	for (size_t i{ 0 }; i < rows; i++)
		data[i] = copy[i];
}

template<typename T>
const T_Matrix3x3<T>& T_Matrix3x3<T>::operator=(const T_Matrix3x3<T>& matrix)
{
	assert(&matrix != this);
	for (size_t i{ 0 }; i < rows; i++)
		data[i] = matrix[i];

	return *this;
}

template<typename T>
T_Vector3<T>& T_Matrix3x3<T>::operator[](size_t index)
{
	assert(index >= 0 && index < rows);
	return data[index];
}

template<typename T>
const T_Vector3<T>& T_Matrix3x3<T>::operator[](size_t index) const
{
	assert(index >= 0 && index < rows);
	return data[index];
}

template<typename T>
T_Matrix3x3<T> operator+(T left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> R;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		R[i] = left + right[i];
	return R;
}

template<typename T>
T_Matrix3x3<T> operator+(const T_Matrix3x3<T>& left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> R;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		R[i] = left[i] + right[i];
	return R;
}

template<typename T>
T_Matrix3x3<T> operator-(T left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> R;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		R[i] = left - right[i];
	return R;
}

template<typename T>
T_Matrix3x3<T> operator-(const T_Matrix3x3<T>& left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> R;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		R[i] = left[i] - right[i];
	return R;
}

template<typename T>
T_Matrix3x3<T> operator*(T left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> R;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		R[i] = left * right[i];
	return R;
}

template<typename T>
T_Matrix3x3<T> operator*(const T_Matrix3x3<T>& left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> R;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		R[i] = left[i] * right[i];
	return R;
}

template<typename T>
T_Matrix3x3<T> operator/(T left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> R;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		R[i] = left / right[i];
	return R;
}

template<typename T>
T_Matrix3x3<T> operator/(const T_Matrix3x3<T>& left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> R;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		R[i] = left[i] / right[i];
	return R;
}

template<typename T>
std::ostream& operator<<(std::ostream& ost, const T_Matrix3x3<T>& matrix)
{
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		ost << matrix[i] << "\n";
	return ost;
}

template<typename T>
T_Matrix3x3<T> T_Matrix3x3<T>::translate(const T_Matrix3x3<T>& matrix, const T_Vector3<T>& vector)
{
	T_Matrix3x3<T> R(matrix);
	R[2].x += vector.x;
	R[2].y += vector.y;
	return R;
}

template<typename T>
T_Matrix3x3<T> T_Matrix3x3<T>::scale(const T_Matrix3x3<T>& matrix, const T_Vector3<T>& vector)
{
	T_Matrix3x3<T> R(matrix);
	R[0].x *= vector.x;
	R[1].y *= vector.y;
	R[2].z *= vector.z;
	return R;
}

#endif