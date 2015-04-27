#ifndef BUW_POINT2D_HPP
#define BUW_POINT2D_HPP

class Point2d 
{
public:
	Point2d(double x, double y);
	~Point2d();
	double x(double point_x) const;
	double y(double point_y) const;

private:
	double x_;
	double y_;
};

#endif	