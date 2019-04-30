#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle{

    public:

        Rectangle();

        Rectangle(Vec2 const& p1, Vec2 const& p2, Color const& col);

        // Umfang des Rechteckes
        float circumference() const;
        // Zeichnet achsenparalleles Rechteck aus 4 Linien
        void draw(Window const& win) const;
        // Wie obige mit einstellbarer Liniendicke
        void draw(Window const& win, float thickness) const;

    private:

        // Rechteck besteht aus zwei Punkten (links unten und rechts oben)
        // sowie einer Linienfarbe
        Vec2 min_{};
        Vec2 max_{};
        Color color_{};

};

#endif