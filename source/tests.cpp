#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "point2d.hpp"
#include <cmath>

const double PI = 3.1415926;

TEST_CASE("test_point2d_pos", "[Point2d]")
{
  Point2d p1{};
  REQUIRE(p1.x() == 0);
  REQUIRE(p1.y() == 0);

  Point2d p2{34.225, 87.933};
  REQUIRE(p2.x() == Approx(34.225));
  REQUIRE(p2.y() == Approx(87.933));
}

TEST_CASE("test_translate", "[translate]")
{
  Point2d p{34.225, 87.933};
  p.translate(20.005, 0.57);
  REQUIRE(p.x() == Approx(54.23));
  REQUIRE(p.y() == Approx(88.503));
}

TEST_CASE("test_rotate", "[rotate]")
{
  Point2d p{2.00,2.00};
  p.rotate(PI);
  REQUIRE(p.x() == Approx(-2.00));
  REQUIRE(p.y() == Approx(-2.00));

  Point2d p2{-1.3, -56.44};
  p2.rotate(2*PI);
  REQUIRE(p2.x() == Approx(-1.3));
  REQUIRE(p2.y() == Approx(-56.44));
}

TEST_CASE("test_rotate_point", "[rotate]")
{
  Point2d p3{0,0};
  Point2d p4{1,1};
  p3.rotate(PI, p4);
  REQUIRE(p3.x() == Approx(2));
  REQUIRE(p3.y() == Approx(2));

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
