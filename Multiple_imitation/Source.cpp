#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Square {
protected:
    double side;
public:
    Square(double s) : side(s) {}
    double getSide() const { return side; }
    double getArea() const { return side * side; }
};

class Circle {
protected:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getRadius() const { return radius; }
    double getArea() const { return M_PI * radius * radius; }
};

class InscribedCircle : public Square, public Circle {
public:
    InscribedCircle(double side) : Square(side), Circle(side / 2) {}

    void display() const {
        std::cout << "Square with side: " << Square::getSide() << "\n";
        std::cout << "Inscribed circle with radius: " << Circle::getRadius() << "\n";
        std::cout << "Square area: " << Square::getArea() << "\n";
        std::cout << "Inscribed circle area: " << Circle::getArea() << "\n";
    }
};

int main() {
    double side;
    std::cout << "Enter the side of the square: ";
    std::cin >> side;

    InscribedCircle shape(side);
    shape.display();

    return 0;
}