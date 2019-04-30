#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

// Klasse fuer einen Kreis

class Circle{

    public:

    Circle();

    Circle(float r, Vec2 const& mp, Color const& col);
    // Umfang des Kreises
    float circumference() const;

    void draw(Window const& win);

    private:

        // Kreis besteht aus Mittelpunkt und Radius sowie einer
        // Liniesfarbe
        float radius_ = 0.0f;
        Vec2 midpoint_{};
        Color color_{};

};

#endif