#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"


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

TEST_CASE("describe_operator*_mat2*vec*", "[operator*]"){
  Mat2 Testobjekt_16{3.0f, 2.0f, 1.0f, 0.0f};
  Vec2 Testobjekt_17{-1.0f, -4.0f};
  Vec2 Testobjekt_18 = Testobjekt_16 * Testobjekt_17;
  REQUIRE(Testobjekt_18.x == -11);
  REQUIRE(Testobjekt_18.y == -1);
  Vec2 Testobjekt_19 = Testobjekt_18 * Testobjekt_16;
  REQUIRE(Testobjekt_19.x == -35);
  REQUIRE(Testobjekt_19.y == -11);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
