#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>
#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "mat2.hpp"

void draw_second_hand(Window const& win, float seconds, float thickness, float length, Color const& col, Vec2 const& center){
    Vec2 start_point{center.x, center.y - length};
    float rotation = ((2 * M_PI) / 60) * seconds;
    Mat2 rotation_mat2 = make_rotation_mat2(rotation);
    Vec2 new_point = center + (rotation_mat2 * (start_point - center));
    win.draw_line(center.x, center.y, new_point.x, new_point.y,
                col.r, col.g, col.b, thickness);
}

void draw_minutes_hand(Window const& win, float minutes, float thickness, float length, Color const& col, Vec2 const& center){
    Vec2 start_point{center.x, center.y - length};
    float rotation = ((2 * M_PI) / 60) * minutes;
    Mat2 rotation_mat2 = make_rotation_mat2(rotation);
    Vec2 new_point = center + (rotation_mat2 * (start_point - center));
    win.draw_line(center.x, center.y, new_point.x, new_point.y,
                col.r, col.g, col.b, thickness);
}

void draw_hours_hand(Window const& win, float hours, float thickness, float length, Color const& col, Vec2 const& center){
    Vec2 start_point{center.x, center.y - length};
    float rotation = ((2 * M_PI) / 60) * hours;
    Mat2 rotation_mat2 = make_rotation_mat2(rotation);
    Vec2 new_point = center + (rotation_mat2 * (start_point - center));
    win.draw_line(center.x, center.y, new_point.x, new_point.y,
                col.r, col.g, col.b, thickness);
}

int main(int argc, char* argv[]){
    Window win{std::make_pair(850, 850)};

    Vec2 clock_midpoint{std::get<0>(win.window_size()) / 2, std::get<1>(win.window_size()) / 2};
    float clock_radius = 400.0f;
    Color clock_color{1.0f, 20.0f / 255, 147.0f / 255};
    Circle Clock(clock_radius, clock_midpoint, clock_color);

    Color second_hand_color{0.0f, 0.0f, 128.0f / 255};
    Color minutes_hand_color{1.0f, 0.0f, 1.0f};
    Color hours_hand_color{0.0f, 1.0f, 1.0f};

    while (!win.should_close()){
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS){
            win.close();
        }

        float time_since_start = win.get_time();
        float seconds = fmod(time_since_start, 60);
        float minutes = fmod(time_since_start, 3600) / 60;
        float hours = fmod(time_since_start, 43200) / 3600;
        

        auto mouse_position = win.mouse_position();

        Vec2 mouse_position_vec2{std::get<0>(mouse_position), std::get<1>(mouse_position)};

        if (Clock.is_inside(mouse_position_vec2) == true){
            Clock.draw(win, 7.0f);
        } else {
            Clock.draw(win, 5.0f);
        }

        draw_second_hand(win, seconds, 1.2f, 380.0f, second_hand_color, clock_midpoint);
        draw_minutes_hand(win, minutes, 2.4f, 360.0f, minutes_hand_color, clock_midpoint);
        draw_hours_hand(win, hours, 3.5f, 300.0f, hours_hand_color, clock_midpoint);
        
        win.update();
    }

    std::cout << win.get_time() << "\n";

    return 0;
}