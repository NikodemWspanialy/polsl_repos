#pragma once
#include "Figure.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Kolo :
    public Figura
{
    const double r;

public:
    Kolo (const double& r): r(r){}

    virtual double pole() const noexcept {
        return r * r * M_PI;
    }
};

