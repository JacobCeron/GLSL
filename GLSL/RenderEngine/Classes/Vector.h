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

	static T magnitud(const Vector<T, N>& v);
	static T dot(const Vector<T, N>& left, const Vector<T, N>& right);
	static Vector<T, N> normalize(const Vector<T, N>& v);
	static Vector<T, 3> cross(const Vector<T, 3>& left, const Vector<T, 3>& right);
};

#include "Vector.inl"