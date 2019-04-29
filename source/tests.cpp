#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "rectangle.hpp"
#include "circle.hpp"


TEST_CASE("describe_Vec2_struct", "[Vec2]"){
  Vec2 Testobjekt_1;
  Vec2 Testobjekt_2{7, 288.88};
  Vec2 Testobjekt_3{-5.5, 200};
  REQUIRE(Testobjekt_1.x == 0);
  REQUIRE(Testobjekt_1.y == 0);
  REQUIRE(Testobjekt_2.x == 7);
  REQUIRE(Testobjekt_2.y == Approx(288.88));
}

TEST_CASE("describe_operator+=", "[operator+=]"){
  Vec2 Testobjekt_1;
  Vec2 Testobjekt_2{-7, 288.88f};
  Testobjekt_1 += Testobjekt_2;
  REQUIRE(Testobjekt_1.x == -7);
  REQUIRE(Testobjekt_1.y == 288.88f);
}

TEST_CASE("describe_operator*=", "[operator*=]"){
  Vec2 Testobjekt_3{-5.5, 200};
  float lambda = 2;
  Testobjekt_3 *= lambda;
  REQUIRE(Testobjekt_3.x == -11);
  REQUIRE(Testobjekt_3.y == 400);
}

TEST_CASE("describe_operator-=", "[operator-=]"){
  Vec2 Testobjekt_77{33, 55};
  Vec2 Testobjekt_88{11, -5};
  Testobjekt_77 -= Testobjekt_88;
  REQUIRE(Testobjekt_77.x == 22);
  REQUIRE(Testobjekt_77.y == 60);
}

TEST_CASE("describe_operator/=", "[operator/="){
  Vec2 Testobjekt_71{-18, 72};
  float lambda = 18;
  Testobjekt_71 /= lambda;
  REQUIRE(Testobjekt_71.x == -1);
  REQUIRE(Testobjekt_71.y == 4);
  Testobjekt_71 /= 0.0f;
  REQUIRE(Testobjekt_71.x == -1);
}

TEST_CASE("describe_operator+", "[operator+]"){
  Vec2 Testobjekt_4{5555.55f, -30};
  Vec2 Testobjekt_5{0.45, 30};
  Vec2 Testobjekt_6 = Testobjekt_4 + Testobjekt_5;
  REQUIRE(Testobjekt_6.x == 5556);
  REQUIRE(Testobjekt_6.y == 0);
}
TEST_CASE("describe_operator-", "[operator-]"){
  Vec2 Testobjekt_7{33, 55};
  Vec2 Testobjekt_8{11, -5};
  Vec2 Testobjekt_9 = Testobjekt_7 - Testobjekt_8;
  REQUIRE(Testobjekt_9.x == 22);
  REQUIRE(Testobjekt_9.y == 60);
}

TEST_CASE("describe_operator*", "[operator*]"){
  Vec2 Testobjekt_10{-5.5, 200};
  float lambdo = 2.5f;
  float lambda = 2;
  Vec2 Testobjekt_11 = Testobjekt_10 * lambdo;
  REQUIRE(Testobjekt_11.x == -13.75f);
  REQUIRE(Testobjekt_11.y == 500);
  Vec2 Testobjekt_12 = lambda * Testobjekt_11;
  REQUIRE(Testobjekt_12.x == -27.5f);
  REQUIRE(Testobjekt_12.y == 1000);
}
TEST_CASE("describe_operator/", "[operator/]"){
  Vec2 Testobjekt_13{12000.8f, -44.0f};
  float zahl = 2;
  Vec2 Testobjekt_14 = Testobjekt_13 / zahl;
  REQUIRE(Testobjekt_14.x == 6000.4f);
  REQUIRE(Testobjekt_14.y == -22);
  Vec2 Testobjekt_14halb = Testobjekt_14 / 0.0f;
  REQUIRE(Testobjekt_14halb.y == -22);
}

TEST_CASE("describe_operator*=_mat2", "[operator*=]"){
  Mat2 Testobjekt_15{5.0f, -2.0f, 3.0f, 4.0f};
  Mat2 Testobjekt_16{3.0f, 2.0f, -1.0f, 3.0f};
  Testobjekt_15 *= Testobjekt_16;
  REQUIRE(Testobjekt_15.e_00 == 17);
  REQUIRE(Testobjekt_15.e_01 == 4);
  REQUIRE(Testobjekt_15.e_10 == 5);
  REQUIRE(Testobjekt_15.e_11 == 18);
}

TEST_CASE("describe_operator*_mat2*vec", "[operator*]"){
  Mat2 Testobjekt_16{3.0f, 2.0f, 1.0f, 0.0f};
  Vec2 Testobjekt_17{-1.0f, -4.0f};
  Vec2 Testobjekt_18 = Testobjekt_16 * Testobjekt_17;
  REQUIRE(Testobjekt_18.x == -11);
  REQUIRE(Testobjekt_18.y == -1);
  Vec2 Testobjekt_19 = Testobjekt_18 * Testobjekt_16;
  REQUIRE(Testobjekt_19.x == -35);
  REQUIRE(Testobjekt_19.y == -11);
}

TEST_CASE("describe_function_det", "[det()]"){
  Mat2 Testobjekt_20{1.0f, -2.0f, 3.0f, -4.0f};
  float det_20 = Testobjekt_20.det();
  REQUIRE(det_20 == 2);
}

TEST_CASE("describe_ operator*=_mat2*float", "[operator*=]"){
  Mat2 Testobjekt_20halb{1.0f, -2.0f, 3.0f, -4.0f};
  Testobjekt_20halb *= 1.5f;
  REQUIRE(Testobjekt_20halb.e_00 == 1.5);
  REQUIRE(Testobjekt_20halb.e_01 == -3);
  REQUIRE(Testobjekt_20halb.e_10 == 4.5);
  REQUIRE(Testobjekt_20halb.e_11 == -6);
}

TEST_CASE("describe_function_inverse()", "[inverse()]"){
  Mat2 Testobjekt_21{1.0f, -2.0f, 3.0f, -4.0f};
  Mat2 Testobjekt_22 = inverse(Testobjekt_21);
  REQUIRE(Testobjekt_22.e_00 == -2);
  REQUIRE(Testobjekt_22.e_01 == 1);
  REQUIRE(Testobjekt_22.e_10 == -1.5);
  REQUIRE(Testobjekt_22.e_11 == 0.5);
}

TEST_CASE("describe_operator*_mat2*float", "[operator]"){
  Mat2 Testobjekt_20halb{1.0f, -2.0f, 3.0f, -4.0f};
  Mat2 Testobjekt_21halb = Testobjekt_20halb * 1.5f;
  REQUIRE(Testobjekt_21halb.e_00 == 1.5);
  REQUIRE(Testobjekt_21halb.e_01 == -3);
  REQUIRE(Testobjekt_21halb.e_10 == 4.5);
  REQUIRE(Testobjekt_21halb.e_11 == -6);
  Mat2 Testobjekt_22halb = -2.0f * Testobjekt_21halb;
  REQUIRE(Testobjekt_22halb.e_00 == -3);
  REQUIRE(Testobjekt_22halb.e_01 == 6);
  REQUIRE(Testobjekt_22halb.e_10 == -9);
  REQUIRE(Testobjekt_22halb.e_11 == 12);
}

TEST_CASE("describe_function_transpose()", "[transpose()]"){
  Mat2 Testobjekt_23{1.0f, -2.0f, 3.0f, -4.0f};
  Mat2 Testobjekt_23t = transpose(Testobjekt_23);
  REQUIRE(Testobjekt_23t.e_00 == Testobjekt_23.e_00);
  REQUIRE(Testobjekt_23t.e_01 == Testobjekt_23.e_10);
  REQUIRE(Testobjekt_23t.e_10 == Testobjekt_23.e_01);
  REQUIRE(Testobjekt_23t.e_11 == Testobjekt_23.e_11);
}

TEST_CASE("describe_function_make_rotation_"){
  Mat2 Testobjekt_24{1.0f, -2.0f, 3.0f, -4.0f};
  float phi = 0.25f * M_PI;
  Mat2 Testobjekt_Rotationsmatrix = make_rotation_mat2(phi);
  double e_00 = Testobjekt_Rotationsmatrix.e_00;
  double e_01 = Testobjekt_Rotationsmatrix.e_01;
  double e_10 = Testobjekt_Rotationsmatrix.e_10;
  double e_11 = Testobjekt_Rotationsmatrix.e_11;
  REQUIRE(e_00 == Approx(sqrtf(2.0f) / 2.0f).epsilon(0.01));
  REQUIRE(e_01 == Approx(-(sqrtf(2.0f) / 2.0f)).epsilon(0.01));
  REQUIRE(e_10 == Approx(sqrtf(2.0f) / 2.0f).epsilon(0.01));
  REQUIRE(e_11 == Approx(sqrtf(2.0f) / 2.0f).epsilon(0.01));
}

TEST_CASE("describe_struct_color", "[color]"){
  Color Testobjekt_25{};
  REQUIRE(Testobjekt_25.r == 0.5f);
  REQUIRE(Testobjekt_25.g == 0.5f);
  REQUIRE(Testobjekt_25.b == 0.5f);
}

TEST_CASE("describe_function_norm", "[norm]"){
  Vec2 Testobjekt_26{20.0f, 0.0f};
  Vec2 Testobjekt_27{-2.0f, -4.0f};
  float test1 = Testobjekt_26.norm();
  float test2 = Testobjekt_27.norm();
  REQUIRE(test1 == 20);
  REQUIRE(test2 == Approx(sqrtf(20)).epsilon(0.01));
}

TEST_CASE("describe_class_rectangle", "[rectangle]"){
  Vec2 Vektor_1{3.0f, 5.0f};
  Vec2 Vektor_2{5.5f, 3.5f};
  Vec2 Vektor_3{-2.0f, -2.0f};
  Color color{};
  Rectangle Testobjekt_28(Vektor_1, Vektor_2, color);
  Rectangle Testobjekt_29(Vektor_1, Vektor_3, color);
  float circumference = Testobjekt_28.circumference();
  REQUIRE(circumference == 8);
}

TEST_CASE("describe_class_circle", "[circle]"){
  Vec2 Vektor{};
  Color color{};
  Circle Testobjekt_29(2.0f, Vektor, color);
  float circumference = Testobjekt_29.circumference();
  REQUIRE(circumference == Approx(2 * 2 * M_PI).epsilon(0.01));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
