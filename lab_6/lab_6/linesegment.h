#include "Point.h"
class LineSegment : public Point {
public:
    LineSegment(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0);
    void move(double dx, double dy);
    void rotate(double angle);
    void resize(double factor);
    void setColor(std::string color);
private:
    Point p1, p2;
};
