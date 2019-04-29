#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"

class Rectangle{

    public:
        Rectangle(Vec2 const& p1, Vec2 const& p2)
        : min_(p1), max_(p2)
        {}

    private:
        Vec2 min_{0.0f, 0.0f};
        Vec2 max_{0.0f, 0.0f};

};

#endif