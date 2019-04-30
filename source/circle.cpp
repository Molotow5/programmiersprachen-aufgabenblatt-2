#include <math.h>
#include "circle.hpp"

Circle::Circle():
    radius_{200.0f}, midpoint_{350.0f,350.0f}, color_{}
    {}

Circle::Circle(float r, Vec2 const& mp, Color const& col)
        : radius_(r), midpoint_(mp), color_(col)
        {}

float Circle::circumference() const{
    float result = 2.0f * M_PI * radius_;
    return result;
}