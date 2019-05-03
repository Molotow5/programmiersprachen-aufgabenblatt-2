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
    // Funktion zum reichnen des Kreises in ein Window
    void draw(Window const& win) const;
    // Wie obige mit einstellbarer Liniendicke
    void draw(Window const& win, float thickness) const;

    bool is_inside(Vec2 const& point) const;

    private:

        // Kreis besteht aus Mittelpunkt und Radius sowie einer
        // Liniesfarbe
        float radius_ = 0.0f;
        Vec2 midpoint_{};
        Color color_{};

};

#endif