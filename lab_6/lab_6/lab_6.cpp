#include <iostream>
#include "LineSegment.h"
int main() {
    LineSegment line(0, 0, 1, 1);
    int choice;
    do {
        std::cout << "1. Move\n2. Rotate\n3. Resize\n4. Set Color\n5. Exit\n";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            double dx, dy;
            std::cout << "Enter dx and dy: ";
            std::cin >> dx >> dy;
            line.move(dx, dy);
            break;
        }
        case 2: {
            double angle;
            std::cout << "Enter angle: ";
            std::cin >> angle;
            line.rotate(angle);
            break;
        }
        case 3: {
            double factor;
            std::cout << "Enter resize factor: ";
            std::cin >> factor;
            line.resize(factor);
            break;
        }
        case 4: {
            std::string color;
            std::cout << "Enter color: ";
            std::cin >> color;
            line.setColor(color);
            break;
        }
        }
    } while (choice != 5);
    return 0;
}