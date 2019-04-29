#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class Rectangle{

    public:
        Rectangle(Vec2 const& p1, Vec2 const& p2, Color const& col)
        : min_(p1), max_(p2), color_(col)
        {}

        float circumference() const;

    private:
        Vec2 min_{};
        Vec2 max_{};
        Color color_{};

};

#endif