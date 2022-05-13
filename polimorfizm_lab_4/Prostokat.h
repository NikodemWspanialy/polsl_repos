#pragma once
#include "Figure.h"
class Prostokat : public Figura
{
	double a;
	double b;
public:
	Prostokat(const double a, const double b) : a(a), b(b) {}

	virtual double pole() const noexcept {
		return a * b;
	}
};

