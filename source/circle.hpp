#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"

// Klasse fuer einen Kreis

class Circle{

    public:

    Circle(float r, Vec2 const& mp)
        : radius_(r), midpoint_(mp)
        {}

    private:

        float radius_ = 0.0f;
        Vec2 midpoint_{0, 0};

};

#endif