#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>
#include "rectangle.hpp"
#include "circle.hpp"


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  Vec2 Vektor_Rec_1_min{200.0f, 600.0f};
  Vec2 Vektor_Rec_1_max{600.0f, 200.0f};
  Vec2 Vektor_Rec_2_min{100.0f, 700.0f};
  Vec2 Vektor_Rec_2_max{700.0f, 100.0f};
  Vec2 Vektor_Cir_1{400.0f, 400.0f};
  Vec2 Vektor_Cir_2{Vektor_Cir_1};

  Color Col_Rec_1{1.0f, 0.0f, 0.0f};
  Color Col_Rec_2{255.0f, 127 / 255.0f, 0.0f};
  Color Col_Cir_1{0.0f, 0.0f, 1.0f};
  Color Col_Cir_2{139.0f / 255.0f, 90.0f / 255.0f, 43.0f / 255.0f};

  Rectangle Rec_1(Vektor_Rec_1_min, Vektor_Rec_1_max, Col_Rec_1);
  Rectangle Rec_2{};
  Rectangle Rec_3(Vektor_Rec_2_min, Vektor_Rec_2_max, Col_Rec_2);

  Circle Cir_1(200.0f, Vektor_Cir_1, Col_Cir_1);
  Circle Cir_2(100.0f, Vektor_Cir_2, Col_Cir_2);

  std::vector<Circle> Cir_Vector;
  Cir_Vector.push_back(Cir_1);
  Cir_Vector.push_back(Cir_2);

  std::vector<float> Cir_thickness;
  Cir_thickness.push_back(1.0f);
  Cir_thickness.push_back(4.0f);

  std::vector<Rectangle> Rec_Vector;
  Rec_Vector.push_back(Rec_1);
  Rec_Vector.push_back(Rec_2);
  Rec_Vector.push_back(Rec_3);

  std::vector<float> Rec_thickness;
  Rec_thickness.push_back(1.5f);
  Rec_thickness.push_back(1.0f);
  Rec_thickness.push_back(7.5f);

  
  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    auto mouse_position = win.mouse_position();

    Vec2 mouse_position_vec2{std::get<0>(mouse_position), std::get<1>(mouse_position)};

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    //Rec_1.draw(win);
    //Rec_2.draw(win);
    win.draw_line(100.0f, 100.0f, 700.0f, 700.0f, 0.0f, 1.0f, 0.0f);
    //Cir_1.draw(win);
    //Cir_2.draw(win, 10.0f);
    //Rec_3.draw(win, 15.0f);

    for (int i = 0; i < Cir_Vector.size(); ++i){
      if (Cir_Vector[i].is_inside(mouse_position_vec2) == true){
        Cir_Vector[i].draw(win, Cir_thickness[i] * 2);
      } else {
        Cir_Vector[i].draw(win, Cir_thickness[i]);
      }
    }

    for (int i = 0; i < Rec_Vector.size(); ++i){
      if (Rec_Vector[i].is_inside(mouse_position_vec2) == true){
        Rec_Vector[i].draw(win, Rec_thickness[i] * 2);
      } else {
        Rec_Vector[i].draw(win, Rec_thickness[i]);
      }
    }
    
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    win.update();
  }

  return 0;
}
