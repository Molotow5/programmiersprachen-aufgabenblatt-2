#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"



TEST_CASE("describe_Vec2_struct", "[Vec2]"){
  Vec2 Testobjekt_1;
  Vec2 Testobjekt_2{7,288.88};
  REQUIRE(Testobjekt_1.x == 0);
  REQUIRE(Testobjekt_1.y == 0);
  REQUIRE(Testobjekt_2.x == 7);
  REQUIRE(Testobjekt_2.y == Approx(288.88));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
