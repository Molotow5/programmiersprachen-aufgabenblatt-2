#include <math.h>
#include "circle.hpp"

float Circle::circumference() const{
    float result = 2.0f * M_PI * radius_;
    return result;
}