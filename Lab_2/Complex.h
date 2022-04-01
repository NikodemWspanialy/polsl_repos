#pragma once
#include <iostream>
namespace nw {
	class Complex
	{
		double re;
		double im;
	public:
		Complex(const double re = 0.0, const double im = 0.0) noexcept :
			re(re), im(im) {
		}
		//getter	
		double Re() const noexcept {
			return re;
		}
		double Im() const noexcept {
			return im;
		}
		//setter
		void SetRe(const double Re) noexcept { re = Re; }
		void SetIm(const double Im) noexcept { im = Im; }

		bool operator==(const Complex& c) const noexcept {
			return re == c.re and im == c.im;
		}
		bool operator!=(const Complex& c) const noexcept {
			return re != c.re or im != c.im;
			// return !(*this == c)
		}

		Complex& operator+=(const Complex& c) noexcept {
			re += c.re;
			im += c.im;
			return *this;
		}
		Complex operator+(const Complex& c) const noexcept {
			return (re + c.re, im + c.im);
			//return Complex(*this) += c;
			//return Complex(re + c.re, im + c.im);
		}
		Complex& operator++() noexcept {
			++re;
			return *this;
		}
		Complex operator++(int) noexcept {
			Complex ret = *this;
			re += 1;
			return ret;
		}
		Complex operator*(const double& d) noexcept {
			re *= d;
			im *= d;
			return *this;
		}
		Complex operator/(const double& d) noexcept {
			re /= d;
			im /= d;
			return *this;
		}
		Complex operator*(const Complex& c) const noexcept {
			return((c.re * re - c.im * im) , (re * c.im + c.re * im));
		}
	};
	inline std::ostream& operator<<(std::ostream& out, const Complex& c) {
		out << c.Re() << (c.Im() < 0? " - i" : " + i") << abs(c.Im());
		return out;
	}
	inline std::istream& operator>>(std::istream& in, Complex& c) {
		in >> c.Re() >> c.Im();
		return in;
	}
	inline Complex operator*(const double d, const Complex& c) {
		return { d * c.Re(), d * c.Im() };
	}
}

