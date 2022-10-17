#pragma once
#include <string>
namespace nw {

	template<class T> T DefValue() { throw std::exception(); }
	template<> double DefValue() { return 0.0; }
	template<> std::string DefValue() { return "rrr"; }
	template <class T>
	class Vector
	{		
		size_t size;
		T* data;
	public:
		Vector(const size_t size, const T& defValue = 0.0) : size(size), data(new T[size]) {
			for (size_t i = 0; i < size; ++i) {
				data[i] = defValue;
			}
		}
		/*Vector(const size_t size, const, const T& defValue = 0.0) : size(size), data(newT[size]) {
			for (size_t i = 0; i < size_t; ++i) {
				data[i] = defValue;
			}
		}*/
		~Vector() noexcept {
			delete[] data;
		}
		size_t Size() const noexcept {
			return size;
		}
		const T& operator[](const size_t index) const {
			return data[index];
		}
		T& operator[](const size_t index) {
			return data[index];
		}
	};
}

