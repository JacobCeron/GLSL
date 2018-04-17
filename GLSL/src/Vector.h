#pragma once

#include <initializer_list>

template<typename T, size_t N>
class Vector
{
private:
	T m_data[N];

public:
	Vector();
	Vector(const std::initializer_list<T>& list);
	Vector(const Vector<T, N>& copy);

	T& operator[](size_t pos);
	const T& operator[](size_t pos) const;

	const bool empty() const;
	const size_t size() const;

	T* begin();
	const T* begin() const;
	T* end();
	const T* end() const;

	template<typename T, size_t N>
	friend Vector<T, N> operator+(const Vector<T, N>& left, T right);
	template<typename T, size_t N>
	friend Vector<T, N> operator+(T left, const Vector<T, N>& right);
	template<typename T, size_t N>
	friend Vector<T, N> operator+(const Vector<T, N>& left, const Vector<T, N>& right);

	template<typename T, size_t N>
	friend Vector<T, N> operator-(const Vector<T, N>& left, T right);
	template<typename T, size_t N>
	friend Vector<T, N> operator-(T left, const Vector<T, N>& right);
	template<typename T, size_t N>
	friend Vector<T, N> operator-(const Vector<T, N>& left, const Vector<T, N>& right);

	template<typename T, size_t N>
	friend Vector<T, N> operator*(const Vector<T, N>& left, T right);
	template<typename T, size_t N>
	friend Vector<T, N> operator*(T left, const Vector<T, N>& right);
	template<typename T, size_t N>
	friend Vector<T, N> operator*(const Vector<T, N>& left, const Vector<T, N>& right);

	template<typename T, size_t N>
	friend Vector<T, N> operator/(const Vector<T, N>& left, T right);
	template<typename T, size_t N>
	friend Vector<T, N> operator/(T left, const Vector<T, N>& right);
	template<typename T, size_t N>
	friend Vector<T, N> operator/(const Vector<T, N>& left, const Vector<T, N>& right);

	template<typename T, size_t N>
	static T magnitud(const Vector<T, N>& u)
	{
		T sum{ 0 };
		for (const auto& element : u)
			sum += (element * element);
		std::cout << sum << std::endl;
		return sqrt(sum);
	}
	/*template<float, size_t N>
	static Vector<float, N> normalize(const Vector<float, N>& u);
	template<typename T, size_t N>
	static T dot(const Vector<T, N>& u, const Vector<T, N>& v);
	/*template<typename T, 3>
	static Vector<T, N> cross(const Vector<T, N>& u, const Vector<T, N>& v);*/
};

#include "Vector.inl"