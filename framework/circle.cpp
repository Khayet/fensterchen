#include "circle.hpp"
#include <cmath>

Circle::Circle() :
  center_{ Point2d(0.0, 0.0) },
  radius_{0.0},
  color_{0.0, 0.0, 0.0} {}

Circle::Circle(Point2d const& p, double r) :
  center_{p},
  radius_{r}, 
  color_{0.0, 0.0, 0.0} {}

Circle::Circle(Point2d const& p, double r, Color const& clr):
  center_{p},
  radius_{r},
  color_{clr} {}

void Circle::draw(Window win) const
{
  //TODO
}

void Circle::draw(Window win, Color const& clr) const
{
  //TODO
}

double Circle::area() const
{
  return  PI * radius_*radius_;
}

double Circle::diameter() const 
{ 
  return 2*radius_; 
}

double Circle::circumference() const 
{ 
  return 2*radius_*PI; 
}

double Circle::leftBound() const
{
  return center_.x() - radius_;
}

double Circle::rightBound() const
{
  return center_.x() + radius_;
}

double Circle::upperBound() const
{
  return center_.y() - radius_;
}

double Circle::lowerBound() const
{
  return center_.y() + radius_;
}