#include <cmath>
#include <map>
#include <string>
class Point {
public:
    Point(double x = 0, double y = 0);
    void move(double dx, double dy);
    void rotate(double angle);
    void resize(double factor);
    void setColor(std::string color);
protected:
    double x, y;
    int color;
    std::map<std::string, int> colorMap = { {"red", 1}, {"green", 2}, {"blue", 3}, {"yellow", 4}, {"black", 5} };
};
