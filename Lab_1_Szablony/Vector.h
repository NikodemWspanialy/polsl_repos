#pragma once
#include <string>
#include<functional>
namespace nw {
	template<class T> T DefValue() { throw std::exception(); }
	template<> double DefValue() { return 0.0; }
	template<> int DefValue() { return 0; }
	template<> float DefValue() { return 0; }
	template<> char DefValue() { return ' '; }
	template<> std::string DefValue() { return ""; }
	template <class T>
	class Vector
	{
		size_t size;
		T* data;
	public:
		Vector(const size_t size, const T& defValue = DefValue<T>()) : size(size), data(new T[size]) {
			for (size_t i = 0; i < size; ++i) {
				data[i] = defValue;
			}
		}
		/*Vector(const size_t size, const std::function<T(const size_t)>& f) : size(size), data(new T[size]) {
			for (size_t i = 0; i < size; ++i) {
				data[i] = f(i);
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
