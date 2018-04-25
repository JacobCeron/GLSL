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
T_Matrix3x3<T>::T_Matrix3x3(const T_Vector3<T>& v1, const T_Vector3<T>& v2, const T_Vector3<T>& v3)
{
	data[0] = v1;
	data[1] = v2;
	data[2] = v3;
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
	T_Matrix3x3<T> Result;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		Result[i] = left + right[i];
	return Result;
}

template<typename T>
T_Matrix3x3<T> operator+(const T_Matrix3x3<T>& left, T right)
{
	return right + left;
}

template<typename T>
T_Matrix3x3<T> operator+(const T_Matrix3x3<T>& left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> Result;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		Result[i] = left[i] + right[i];
	return Result;
}

template<typename T>
T_Matrix3x3<T> operator-(T left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> Result;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		Result[i] = left - right[i];
	return Result;
}

template<typename T>
T_Matrix3x3<T> operator-(const T_Matrix3x3<T>& left, T right)
{
	T_Matrix3x3<T> Result;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		Result[i] = left[i] - right;
	return Result;
}

template<typename T>
T_Matrix3x3<T> operator-(const T_Matrix3x3<T>& left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> Result;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		Result[i] = left[i] - right[i];
	return Result;
}

template<typename T>
T_Matrix3x3<T> operator*(T left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> Result;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		Result[i] = left * right[i];
	return Result;
}

template<typename T>
T_Matrix3x3<T> operator*(const T_Matrix3x3<T>& left, T right)
{
	return right * left;
}

template<typename T>
T_Vector3<T> operator*(const T_Vector3<T>& left, const T_Matrix3x3<T>& right)
{
	T_Vector3<T> Result;
	Result[0] = T_Vector3<T>::dot(left, right[0]);
	Result[1] = T_Vector3<T>::dot(left, right[1]);
	Result[2] = T_Vector3<T>::dot(left, right[2]);

	return Result;
}

template<typename T>
T_Vector3<T> operator*(const T_Matrix3x3<T>& left, const T_Vector3<T>& right)
{
	return right * left;
}

template<typename T>
T_Matrix3x3<T> operator*(const T_Matrix3x3<T>& left, const T_Matrix3x3<T>& right)
{
	T_Matrix3x3<T> Result;
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
	{
		T_Vector3<T> temp(left[0][i], left[1][i], left[2][i], left[3][i]);
		Result[0][i] = T_Vector3<T>::dot(temp, right[0]);
		Result[1][i] = T_Vector3<T>::dot(temp, right[1]);
		Result[2][i] = T_Vector3<T>::dot(temp, right[2]);
	}
	return Result;
}

template<typename T>
std::ostream& operator<<(std::ostream& ost, const T_Matrix3x3<T>& matrix)
{
	for (size_t i{ 0 }; i < T_Matrix3x3<T>::rows; i++)
		ost << matrix[i] << "\n";
	return ost;
}

template<typename T>
T_Matrix3x3<T> T_Matrix3x3<T>::transpose(const T_Matrix3x3<T>& matrix)
{
	return T_Matrix3x3<T>
		(
			T_Vector3<T>(matrix[0][0], matrix[1][0], matrix[2][0],
			T_Vector3<T>(matrix[0][1], matrix[1][1], matrix[2][1],
			T_Vector3<T>(matrix[0][2], matrix[1][2], matrix[2][2]
			);
}

template<typename T>
T_Matrix3x3<T> T_Matrix3x3<T>::inverse(const T_Matrix3x3<T>& matrix)
{
	return T_Matrix3x3<T>();
}

template<typename T>
T_Matrix3x3<T> T_Matrix3x3<T>::translate(const T_Matrix3x3<T>& matrix, const T_Vector3<T>& vector)
{
	T_Matrix3x3<T> Result(matrix);
	Result[2].x += vector.x;
	Result[2].y += vector.y;
	Result[2].z += vector.z;
	return R;
}

template<typename T>
T_Matrix3x3<T> T_Matrix3x3<T>::scale(const T_Matrix3x3<T>& matrix, const T_Vector3<T>& vector)
{
	T_Matrix3x3<T> Result(matrix);
	Result[0].x *= vector.x;
	Result[1].y *= vector.y;
	Result[2].z *= vector.z;
	return R;
}

template<typename T>
T_Matrix3x3<T> T_Matrix3x3<T>::rotate(const T_Matrix3x3<T>& matrix, float angle, const T_Vector3<T>& axis)
{
	T_Matrix3x3<T> Rotate;

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

	T_Matrix3x3<T> Result;
	Result[0] = matrix[0] * Rotate;
	Result[1] = matrix[1] * Rotate;
	Result[2] = matrix[2] * Rotate;

	return Result;
}

#endif