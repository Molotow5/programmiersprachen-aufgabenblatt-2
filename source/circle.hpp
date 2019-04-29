#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"

// Klasse fuer einen Kreis

class Circle{

    public:

    Circle(float r, Vec2 const& mp, Color const& col)
        : radius_(r), midpoint_(mp), color_(col)
        {}

    private:

        float radius_ = 0.0f;
        Vec2 midpoint_{};
        Color color_{};

};

#endif