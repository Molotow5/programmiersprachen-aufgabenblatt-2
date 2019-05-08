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
        void draw(Window const& win);
        // Wie obige mit einstellbarer Liniendicke
        void draw(Window const& win, float thickness);
        // Check ob Koirdinaten in der Figur liegen
        bool is_inside(Vec2 const& point) const;

    private:

        // Rechteck besteht aus zwei Punkten (links unten und rechts oben)
        // sowie einer Linienfarbe
        Vec2 min_{};
        Vec2 max_{};
        Color color_{};

};

#endif