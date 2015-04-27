#include "point2d.hpp"

Point2d::Point2d():
	x_{0},
	y_{0} {}

Point2d::Point2d(double x, double y):
	x_{x},
	y_{y} {}

Point2d::~Point2d() {
	std::cout << "point destroyed" << std::endl;
}

double x() {
	return x_;
}

double y() {
	return y_;
}