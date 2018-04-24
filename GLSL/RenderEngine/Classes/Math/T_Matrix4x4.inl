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
std::ostream& operator<<(std::ostream& ost, const T_Matrix4x4<T>& matrix)
{
	for (size_t i{ 0 }; i < T_Matrix4x4<T>::rows; i++)
		ost << matrix[i] << "\n";
	return ost;
}

#endif