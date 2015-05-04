#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "point2d.hpp"
#include "color.hpp"
#include "fensterchen.hpp"

class Rectangle
{
public:
  Rectangle();
  Rectangle(Point2d const&, Point2d const&);
  Rectangle(Point2d const&, Point2d const&, Color const&);

  Point2d upLeft() const { return upLeft_; }
  Point2d botRight() const { return botRight_; }
  Color color() const { return color_; }

  void draw(Window) const;
  void draw(Window, Color const&) const;

  bool isInside(Point2d const&);

  Point2d upRight() const { return Point2d(botRight_.x(), upLeft_.y()); }
  Point2d botLeft() const { return Point2d(upLeft_.x(), botRight_.y()); }

  double width() const;
  double height() const;
  double diameter() const;
  double circumference() const;
  double area() const;

private:
  Point2d upLeft_;
  Point2d botRight_;
  Color color_;
};

#endif //RECTANGLE_HPP