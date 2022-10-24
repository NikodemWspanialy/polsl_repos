#pragma once
#include <string>
#include<functional>
#include <iostream>
namespace nw {
	template<class T> T DefValue() { std::cout << "unknow type"; throw std::exception(); }
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
		Vector(const size_t size = 0, const T& defValue = DefValue<T>()) : size(size), data(new T[size]) {
			for (size_t i = 0; i < size; ++i) {
				data[i] = defValue;
			}
		}
		Vector(const size_t size, const std::function<T(const size_t)>& f) : size(size), data(new T[size]) {
			for (size_t i = 0; i < size; ++i) {
				data[i] = f(i);
			}
		}
		Vector(const Vector& v) noexcept :size(v.sizeGetter()), data(new T[size]) {
			for (size_t i = 0; i < size; i++)
				data[i] = v.data[i];
		}
		Vector(Vector&& v) noexcept :size(v.sizeGetter()), data(v.dataGetter()) {
			v.data = 0;
			v.data = nullptr;
		}

		~Vector() noexcept {
			delete[] data;
		}
		T& operator[](const size_t index) const {
			return data[index];
		}
		T& operator[](const size_t index) {
			return data[index];
		}
		size_t sizeGetter() const noexcept {
			return size;
		}
		T* dataGetter() {
			return data;
		}
		 void pushback(const T& value) noexcept{
			++size;
			T* datatmp;
			datatmp = new T[size];
			for (size_t i = 0; i < size - 1; i++) {
				datatmp[i] = data[i];
			}
			datatmp[size-1] = value;
			data = nullptr;
			data = datatmp;
		}
	    bool operator ==(Vector<T> &b) const {
			if (size != b.sizeGetter())
				return false;
			if (this->size < b.sizeGetter()) {
				for (int i = 0; i < this->size; i++) {
					if (data[i] != b[i])
						return false;
				}
				return true;
			}
			else
			{
				for (int i = 0; i < b.sizeGetter(); i++) {
					if (data[i] != b[i])
						return false;
				}
				return true;
			}
		}
		bool operator !=(Vector<T>& b) const {
			if (size != b.sizeGetter())
				return true;
			if (this->size < b.sizeGetter()) {
				for (int i = 0; i < this->size; i++) {
					if (data[i] != b[i])
						return true;
				}
				return false;
			}
			else
			{
				for (int i = 0; i < b.sizeGetter(); i++) {
					if (data[i] != b[i])
						return true;
				}
				return false;
			}
		}
	};
}
