#include <iostream>
#include <tuple>


class Figure {
public:
    virtual void draw() = 0; 
    virtual void erase() = 0; 
};


class Rectangle : public Figure {
public:
    Rectangle(int x1, int y1, int x2, int y2, int number)
        : x1(x1), y1(y1), x2(x2), y2(y2), number(number) {}

    void draw() override {
        std::cout << "Drawing rectangle with top left corner at (" << x1 << ", " << y1 << "), "
            << "bottom right corner at (" << x2 << ", " << y2 << "), "
            << "and serial number " << number << std::endl;
    }

    void erase() override {
        std::cout << "Erasing rectangle with serial number " << number << std::endl;
    }

    void SetCoordinates(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    std::tuple<int, int, int, int> GetCoordinates() {
        return std::make_tuple(x1, y1, x2, y2);
    }

private:
    int x1, y1, x2, y2; 
    int number;
};

int main() {
    Rectangle rect(2, 5, 10, 10, 1);
    rect.draw();
    rect.erase();
    return 0;
}
