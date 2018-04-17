#include <cassert>

template<typename T, size_t N>
Vector<T, N>::Vector()
{
	for (size_t i{ 0 }; i < size(); i++)
		m_data[i] = 0;
}

template<typename T, size_t N>
Vector<T, N>::Vector(const std::initializer_list<T>& list)
{
	size_t count{ 0 };
	for (const auto& element : list)
	{
		if (count == size())
			break;
		m_data[count++] = element;
	}
}

template<typename T, size_t N>
Vector<T, N>::Vector(const Vector<T, N>& copy)
{
	size_t count{ 0 };
	for (const auto& element : copy)
		m_data[count++] = element;
}

template<typename T, size_t N>
T& Vector<T, N>::operator[](size_t pos)
{
	assert(pos >= 0 && pos < size());
	return m_data[pos];
}

template<typename T, size_t N>
const T& Vector<T, N>::operator[](size_t pos) const
{
	assert(pos >= 0 && pos < size());
	return m_data[pos];
}

template<typename T, size_t N>
const bool Vector<T, N>::empty() const
{
	return (begin() == end());
}

template<typename T, size_t N>
const size_t Vector<T, N>::size() const
{
	return N;
}

template<typename T, size_t N>
T* Vector<T, N>::begin()
{
	return &m_data[0];
}

template<typename T, size_t N>
const T* Vector<T, N>::begin() const
{
	return &m_data[0];
}

template<typename T, size_t N>
T* Vector<T, N>::end()
{
	return &m_data[size()];
}

template<typename T, size_t N>
const T* Vector<T, N>::end() const
{
	return &m_data[size()];
}

template<typename T, size_t N>
Vector<T, N> operator+(const Vector<T, N>& left, T right)
{
	Vector<T, N> res;
	for (size_t i{ 0 }; i < res.size(); i++)
		res[i] = left[i] + right;
	return res;
}

template<typename T, size_t N>
Vector<T, N> operator+(T left, const Vector<T, N>& right)
{
	Vector<T, N> res;
	for (size_t i{ 0 }; i < res.size(); i++)
		res[i] = left + right[i];
	return res;
}

template<typename T, size_t N>
Vector<T, N> operator+(const Vector<T, N>& left, const Vector<T, N>& right)
{
	Vector<T, N> res;
	for (size_t i{ 0 }; i < res.size(); i++)
		res[i] = left[i] + right[i];
	return res;
}

template<typename T, size_t N>
Vector<T, N> operator-(const Vector<T, N>& left, T right)
{
	Vector<T, N> res;
	for (size_t i{ 0 }; i < res.size(); i++)
		res[i] = left[i] - right;
	return res;
}

template<typename T, size_t N>
Vector<T, N> operator-(T left, const Vector<T, N>& right)
{
	Vector<T, N> res;
	for (size_t i{ 0 }; i < res.size(); i++)
		res[i] = left - right[i];
	return res;
}

template<typename T, size_t N>
Vector<T, N> operator-(const Vector<T, N>& left, const Vector<T, N>& right)
{
	Vector<T, N> res;
	for (size_t i{ 0 }; i < res.size(); i++)
		res[i] = left[i] - right[i];
	return res;
}

template<typename T, size_t N>
Vector<T, N> operator*(const Vector<T, N>& left, T right)
{
	Vector<T, N> res;
	for (size_t i{ 0 }; i < res.size(); i++)
		res[i] = left[i] * right;
	return res;
}

template<typename T, size_t N>
Vector<T, N> operator*(T left, const Vector<T, N>& right)
{
	Vector<T, N> res;
	for (size_t i{ 0 }; i < res.size(); i++)
		res[i] = left * right[i];
	return res;
}

template<typename T, size_t N>
Vector<T, N> operator*(const Vector<T, N>& left, const Vector<T, N>& right)
{
	Vector<T, N> res;
	for (size_t i{ 0 }; i < res.size(); i++)
		res[i] = left[i] * right[i];
	return res;
}

template<typename T, size_t N>
Vector<T, N> operator/(const Vector<T, N>& left, T right)
{
	Vector<T, N> res;
	for (size_t i{ 0 }; i < res.size(); i++)
		res[i] = left[i] / right;
	return res;
}

template<typename T, size_t N>
Vector<T, N> operator/(T left, const Vector<T, N>& right)
{
	Vector<T, N> res;
	for (size_t i{ 0 }; i < res.size(); i++)
		res[i] = left / right[i];
	return res;
}

template<typename T, size_t N>
Vector<T, N> operator/(const Vector<T, N>& left, const Vector<T, N>& right)
{
	Vector<T, N> res;
	for (size_t i{ 0 }; i < res.size(); i++)
		res[i] = left[i] / right[i];
	return res;
}