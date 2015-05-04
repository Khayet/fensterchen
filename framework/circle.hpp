#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "point2d.hpp"
#include "color.hpp"
#include "fensterchen.hpp"

const double PI = 3.1415926;

class Circle 
{
public:
    Circle();
    Circle(Point2d const&, double);
    Circle(Point2d const&, double, Color const&);
    
    Point2d center() const { return center_; }
    double radius() const { return radius_; }
    Color color() const { return color_; }

    void draw(Window) const;
    void draw(Window, Color const&) const;

    double area() const;
    double diameter() const;
    double circumference() const;

    double leftBound() const;
    double rightBound() const;
    double upperBound() const;
    double lowerBound() const;

private:
    Point2d center_;
    double radius_;
    Color color_;
};

#endif //CIRCLE_HPP