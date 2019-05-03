#include <math.h>
#include "rectangle.hpp"

Rectangle::Rectangle()
    : min_{400.0f, 600.0f}, max_{600.0f ,500.0f}, color_{}
    {}

Rectangle::Rectangle(Vec2 const& p1, Vec2 const& p2, Color const& col)
    : min_(p1), max_(p2), color_(col)
    {}

float Rectangle::circumference() const{
    Vec2 min_max{max_.x - min_.x, max_.y - max_.y};
    Vec2 max_min{max_.x - max_.x, min_.y - max_.y};
    float result = 2 * min_max.norm() + 2 * max_min.norm();
    return result;
}

void Rectangle::draw(Window const& win) const{
    win.draw_line(min_.x, min_.y,
                min_.x, max_.y,
                color_.r, color_.g, color_.b);
    win.draw_line(min_.x, min_.y,
                max_.x, min_.y,
                color_.r, color_.g, color_.b);
    win.draw_line(max_.x, min_.y,
                max_.x, max_.y,
                color_.r, color_.g, color_.b);
    win.draw_line(min_.x, max_.y,
                max_.x, max_.y,
                color_.r, color_.g, color_.b);
}

void Rectangle::draw(Window const& win, float thickness) const{
    win.draw_line(min_.x, min_.y,
                min_.x, max_.y,
                color_.r, color_.g, color_.b,
                thickness);
    win.draw_line(min_.x, min_.y,
                max_.x, min_.y,
                color_.r, color_.g, color_.b,
                thickness);
    win.draw_line(max_.x, min_.y,
                max_.x, max_.y,
                color_.r, color_.g, color_.b,
                thickness);
    win.draw_line(min_.x, max_.y,
                max_.x, max_.y,
                color_.r, color_.g, color_.b,
                thickness);
}

bool Rectangle::is_inside(Vec2 const& point) const{
    if (min_.x <= max_.x && min_.y >= max_.y){
        if (point.x < max_.x && point.x > min_.x && point.y < min_.y 
            && point.y > max_.y){
                return true;
            } else {
                return false;
            }
    } else if (min_.x > max_.x && min_.y < max_.y){
        if (point.x > max_.x && point.x < min_.x && point.y > min_.y 
            && point.y < max_.y){
                return true;
            } else {
                return false;
            }
    } else if (min_.x <= max_.x && min_.y < max_.y){
        if (point.x < max_.x && point.x > min_.x && point.y > min_.y 
            && point.y < max_.y){
                return true;
            } else {
                return false;
            }
    } else if (min_.x > max_.x && min_.y >= max_.y){
        if (point.x > max_.x && point.x < min_.x && point.y < min_.y 
            && point.y > max_.y){
                return true;
            } else {
                return false;
            }
    }
}