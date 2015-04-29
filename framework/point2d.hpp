#ifndef BUW_POINT2D_HPP
#define BUW_POINT2D_HPP

class Point2d 
{
public:
    Point2d();
    Point2d(double, double);
    ~Point2d();
    double x() const;
    double y() const;
    void translate(double, double);

private:
    double x_;
    double y_;
};

#endif  