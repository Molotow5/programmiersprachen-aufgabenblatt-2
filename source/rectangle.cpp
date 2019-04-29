#include <math.h>
#include "vec2.hpp"
#include "rectangle.hpp"

float Rectangle::circumference() const{
    Vec2 min_max{max_.x - min_.x, max_.y - max_.y};
    Vec2 max_min{max_.x - max_.x, min_.y - max_.y};
    float result = 2 * min_max.norm() + 2 * max_min.norm();
    return result;
}