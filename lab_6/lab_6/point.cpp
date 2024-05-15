#include "Point.h"
Point::Point(double x, double y) : x(x), y(y), color(0) {}
void Point::move(double dx, double dy) { x += dx; y += dy; }
void Point::rotate(double angle) {
    double rad = angle * 3.141592653589793 / 180.0;
    double newX = x * cos(rad) - y * sin(rad);
    double newY = x * sin(rad) + y * cos(rad);
    x = newX;
    y = newY;
}
void Point::resize(double factor) { x *= factor; y *= factor; }
void Point::setColor(std::string color) { this->color = colorMap[color]; }