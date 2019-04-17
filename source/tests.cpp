#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"


TEST_CASE("describe_Vec2_struct", "[Vec2]"){
  Vec2 Testobjekt_1;
  Vec2 Testobjekt_2{7, 288.88};
  Vec2 Testobjekt_3{-5.5, 200};
  float lambda = 2;
  REQUIRE(Testobjekt_1.x == 0);
  REQUIRE(Testobjekt_1.y == 0);
  REQUIRE(Testobjekt_2.x == 7);
  REQUIRE(Testobjekt_2.y == Approx(288.88));
  Testobjekt_1 += Testobjekt_2;
  REQUIRE(Testobjekt_1.x == 7);
  Testobjekt_2 -= Testobjekt_1;
  REQUIRE(Testobjekt_2.y == 0);
  Testobjekt_3 *= lambda;
  REQUIRE(Testobjekt_3.y == 400);
  Testobjekt_3 /= lambda;
  REQUIRE(Approx(Testobjekt_3.x) == -5.5);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
