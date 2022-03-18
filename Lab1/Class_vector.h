#pragma once
#include <iostream>
namespace nw {
	class Vector
	{
		size_t size;
		double* data;
	public:
		Vector(const size_t size, const double value = 0.0) : size(size),
			data(new double[size]) {
			for (size_t i = 0; i < size; ++i) {
				data[i] = value;
			}
		}
		Vector(Vector& v) : size(v.size), data(new  double[size]) {
			for (size_t i = 0; i < size; ++i)
			{
				data[i] = v.data[i];
			} 
		}
		Vector(Vector&& v) noexcept : size(v.size), data(v.data) {
			v.data = 0;
			v.data = nullptr;
		}
		Vector(const std::initializer_list<double>& il) : size(il.size()),
			data(new double[size]) {
			size_t i = 0;
			for (const auto el : il) {
				data[i++] = el;
			}
		}

		~Vector() noexcept {
			delete[] data;
		}
		size_t Size() const noexcept {
			return size;
		}
		double operator[](const size_t i) const {
			return data[i];
		}
		double& operator[](const size_t i) {
			return data[i];
		}
	};
	inline std::ostream& operator << (std::ostream& out, const Vector& v) {
		for (size_t i = 0; i < v.Size (); ++i) {
			out << v[i] << std::endl;
		}
		return out;
	}
}

