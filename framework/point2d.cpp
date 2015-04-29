#include "point2d.hpp"
#include <iostream>

Point2d::Point2d():
    x_{0},
    y_{0} {}

Point2d::Point2d(double x, double y):
    x_{x},
    y_{y} {}

Point2d::~Point2d() {
    std::cout << "point destroyed" << std::endl;
}

double Point2d::x() const {
    return x_;
}

double Point2d::y() const {
    return y_;
}

void Point2d::translate(double dX, double dY) {
    x_ += dX;
    y_ += dY;
}