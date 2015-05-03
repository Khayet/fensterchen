#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "point2d.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

TEST_CASE("point2d_constr", "[Point2d]")
{
  Point2d p1{};
  REQUIRE(p1.x() == 0);
  REQUIRE(p1.y() == 0);
}

TEST_CASE("point2d_constr2", "[Point2d]")
{
  Point2d p2{34.225, 87.933};
  REQUIRE(p2.x() == Approx(34.225));
  REQUIRE(p2.y() == Approx(87.933));  
}

TEST_CASE("point_translate", "[translate]")
{
  Point2d p{34.225, 87.933};
  p.translate(20.005, 0.57);
  REQUIRE(p.x() == Approx(54.23));
  REQUIRE(p.y() == Approx(88.503));
}

TEST_CASE("point_rotate", "[rotate]")
{
  Point2d p{2.00, 2.00};
  p.rotate(PI);
  REQUIRE(p.x() == Approx(-2.00));
  REQUIRE(p.y() == Approx(-2.00));

  Point2d p2{-1.3, -56.44};
  p2.rotate(2*PI);
  REQUIRE(p2.x() == Approx(-1.3));
  REQUIRE(p2.y() == Approx(-56.44));
}

TEST_CASE("point_rotate2", "[rotate]")
{
  Point2d p3{0, 0};
  Point2d p4{1, 1};
  p3.rotate(PI, p4);
  REQUIRE(p3.x() == Approx(2));
  REQUIRE(p3.y() == Approx(2));

}

TEST_CASE("color_constr", "[color]")
{
  Color c{2.0};
  REQUIRE(c.r == Approx(1.0));
}

TEST_CASE("circle_constr", "[circle]")
{
  Circle c{};
  REQUIRE(c.center().x() == Approx(0.0)); 
  REQUIRE(c.center().y() == Approx(0.0));
  REQUIRE(c.radius() == Approx(0.0));
}

TEST_CASE("circle_constr2", "[circle]")
{
  Circle c{ Point2d(2.5, 3.77), 1};
  REQUIRE(c.center().x() == Approx(2.5));
  REQUIRE(c.center().y() == Approx(3.77));
  REQUIRE(c.radius() == Approx(1));
}

TEST_CASE("circle_constr_clr", "[circle]")
{
  Circle c{Point2d(0.0, 0.0), 1.0, Color(0.5, 0.4, 1.0)};
  REQUIRE(c.color().r == Approx(0.5));
}

TEST_CASE("circle_diameter", "[circle]")
{
  Circle c{ {0, 0}, 2};
  REQUIRE(c.diameter() == Approx(4));
}

TEST_CASE("circle_area", "[circle]")
{
  Circle c{ {0, 0}, 2};
  REQUIRE(c.area() == Approx(12.5663706));
}

TEST_CASE("circle_borders", "[circle]")
{
  Circle c{ {0, 0}, 2};
  REQUIRE(c.leftBound() == Approx(-2));
  REQUIRE(c.rightBound() == Approx(2));
  REQUIRE(c.upperBound() == Approx(-2));
  REQUIRE(c.lowerBound() == Approx(2));
}

TEST_CASE("circle_circumference", "[circle]")
{
  Circle c{ {0, 0}, 1};
  REQUIRE(c.circumference() == Approx(2*PI)); 
}

TEST_CASE("rectangle_constr", "[rectangle]")
{
  Rectangle rect{};
  REQUIRE(rect.upLeft().x() == Approx(0.0));
  REQUIRE(rect.botRight().y() == Approx(0.0));
}

TEST_CASE("rectangle_constr2", "[rectangle]")
{
  Rectangle rect{Point2d(0.0, 0.0), Point2d(2.0, 2.0)};
  REQUIRE(rect.botRight().y() == Approx(2.0));
}

TEST_CASE("rectangle_constr_clr", "[rectangle]")
{
  Rectangle rect{Point2d(0.0, 0.0), Point2d(0.0, 0.0), Color(1.0, 0.6, 0.0)};
  REQUIRE(rect.color().g == Approx(0.6));
}

TEST_CASE("rect_circumference", "[rectangle]")
{
  Rectangle rect{Point2d(0.0, 0.0), Point2d(2.0, 2.0)};
  REQUIRE(rect.circumference() == Approx(8.0));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
