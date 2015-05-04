#include <cmath>
#include "rectangle.hpp"

Rectangle::Rectangle():
  upLeft_{0.0, 0.0},
  botRight_{0.0, 0.0},
  color_{0.0, 0.0, 0.0} {}

Rectangle::Rectangle(Point2d const& p1, Point2d const& p2):
  upLeft_{p1},
  botRight_{p2},
  color_{0.0, 0.0, 0.0} {}

Rectangle::Rectangle(Point2d const& p1, Point2d const& p2, Color const& clr):
  upLeft_{p1},
  botRight_{p2},
  color_{clr} {}

void Rectangle::draw(Window win) const 
{
  //top
  win.drawLine((float)upLeft_.x(), (float)upLeft_.y(), (float)upRight().x(),
                (float)upRight().y(),
                (float)color_.r, (float)color_.g, (float)color_.b);

  //bottom
  win.drawLine((float)botLeft().x(), (float)botLeft().y(), (float)botRight_.x(), 
                (float)botRight_.y(),
                (float)color_.r, (float)color_.g, (float)color_.b);

  //left
  win.drawLine((float)upLeft_.x(), (float)upLeft_.y(), (float)botLeft().x(),
                (float)botLeft().y(),
                (float)color_.r, (float)color_.g, (float)color_.b);

  //right
  win.drawLine((float)upRight().x(), (float)upRight().y(), (float)botRight_.x(),
                (float)botRight_.y(),
                (float)color_.r, (float)color_.g, (float)color_.b);
}

void Rectangle::draw(Window win, Color const& clr) const
{
    //top
  win.drawLine((float)upLeft_.x(), (float)upLeft_.y(), (float)upRight().x(),
                (float)upRight().y(),
                (float)clr.r, (float)clr.g, (float)clr.b);

  //bottom
  win.drawLine((float)botLeft().x(), (float)botLeft().y(), (float)botRight_.x(), 
                (float)botRight_.y(),
                (float)clr.r, (float)clr.g, (float)clr.b);

  //left
  win.drawLine((float)upLeft_.x(), (float)upLeft_.y(), (float)botLeft().x(),
                (float)botLeft().y(),
                (float)clr.r, (float)clr.g, (float)clr.b);

  //right
  win.drawLine((float)upRight().x(), (float)upRight().y(), (float)botRight_.x(),
                (float)botRight_.y(),
                (float)clr.r, (float)clr.g, (float)clr.b);
}

bool Rectangle::isInside(Point2d const& p)
{
  if (p.x() > upLeft_.x() && p.x() < botRight_.x()) {
    if (p.y() > upLeft_.y() && p.y() < botRight_.y()) {
      return true;
    } else { return false; }
  } else { return false; }
}

double Rectangle::width() const
{
  return botRight_.x() - upLeft_.x();
}

double Rectangle::height() const
{
  return botRight_.y() - upLeft_.y(); 
}

double Rectangle::diameter() const
{
  //pythagoras
  return std::sqrt(width()*width() + height()*height());
}

double Rectangle::circumference() const
{
  return 2*(height() + width());
}