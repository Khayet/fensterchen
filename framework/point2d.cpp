#include "point2d.hpp"
#include <iostream>
#include <cmath>

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

void Point2d::rotate(double rad) {
  x_ = x_*std::cos(rad) - x_*std::sin(rad);
  y_ = y_*std::sin(rad) + y_*std::cos(rad);
}

void Point2d::rotate(double rad, Point2d p0) {
  x_ = (x_ - p0.x()) * std::cos(rad) - (x_ - p0.x()) * std::sin(rad) 
        + p0.x();
  y_ = (y_ - p0.y()) * std::sin(rad) + (y_ - p0.y()) * std::cos(rad)
        + p0.y();
}