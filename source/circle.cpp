#include <math.h>
#include "circle.hpp"
#include "mat2.hpp"

Circle::Circle():
    radius_{200.0f}, midpoint_{350.0f,350.0f}, color_{}
    {}

Circle::Circle(float r, Vec2 const& mp, Color const& col)
        : radius_(r), midpoint_(mp), color_(col)
        {}

void Circle::draw(Window const& win){
    Vec2 start_point{midpoint_.x - radius_, midpoint_.y};
    Vec2 last_point = start_point;
    for (int i = 1; i < 201; ++i){
        float rotation = ((2 * M_PI) / 200);
        Mat2 rotation_mat2 = make_rotation_mat2(rotation);
        Vec2 new_point = midpoint_ + (rotation_mat2 * (last_point - midpoint_));
        win.draw_line(last_point.x, last_point.y,
                    new_point.x, new_point.y,
                    color_.r, color_.g, color_.b);
        last_point = new_point;
    }
    

}

float Circle::circumference() const{
    float result = 2.0f * M_PI * radius_;
    return result;
}