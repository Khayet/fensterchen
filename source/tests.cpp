#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "point2d.hpp"
#include <cmath>

TEST_CASE("test_point2d_pos", "[Point2d]")
{
    Point2d p1{};
    REQUIRE(p1.x() == 0);
    REQUIRE(p1.y() == 0);

    Point2d p2{34.225, 87.933};
    REQUIRE(p2.x() == Approx(34.225));
    REQUIRE(p2.y() == Approx(87.933));

    p2.translate(20.005, 0.57);
    REQUIRE(p2.x() == Approx(54.23));
    REQUIRE(p2.y() == Approx(88.503));
}

int main(int argc, char *argv[])
{
    return Catch::Session().run(argc, argv);
}
