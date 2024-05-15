#include "LineSegment.h"
LineSegment::LineSegment(double x1, double y1, double x2, double y2) : p1(x1, y1), p2(x2, y2) {}
void LineSegment::move(double dx, double dy) { p1.move(dx, dy); p2.move(dx, dy); }
void LineSegment::rotate(double angle) { p1.rotate(angle); p2.rotate(angle); }
void LineSegment::resize(double factor) { p1.resize(factor); p2.resize(factor); }
void LineSegment::setColor(std::string color) { p1.setColor(color); p2.setColor(color); }