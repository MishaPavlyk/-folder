#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

double calculateDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    Point point1;
    Point point2;

    std::cout << "Enter the coordinates of the first point (x y): ";
    std::cin >> point1.x >> point1.y;

    std::cout << "Enter the coordinates of the second point (x y): ";
    std::cin >> point2.x >> point2.y;

    double distance = calculateDistance(point1, point2);

    std::cout << "The distance between the points is: " << distance << std::endl;

    return 0;
}
