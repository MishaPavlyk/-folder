#include <iostream>
using namespace std;

struct Rectangle {
    int x;
    int y;
    int width;
    int height;
};

void moveRectangle(Rectangle& rect, int dx, int dy) {
    rect.x += dx;
    rect.y += dy;
}

void resizeRectangle(Rectangle& rect, int newWidth, int newHeight) {
    if (newWidth > 0) rect.width = newWidth;
    if (newHeight > 0) rect.height = newHeight;
}

void printRectangle(const Rectangle& rect) {
    cout << "Rectangle: " << endl;
    cout << "  Top-left corner: (" << rect.x << ", " << rect.y << ")" << endl;
    cout << "  Width: " << rect.width << endl;
    cout << "  Height: " << rect.height << endl;
}

int main() {
    Rectangle rect = { 0, 0, 10, 5 };

    cout << "Initial state:" << endl;
    printRectangle(rect);

    moveRectangle(rect, 5, 10);
    cout << "\nAfter moving:" << endl;
    printRectangle(rect);

    resizeRectangle(rect, 20, 15);
    cout << "\nAfter resizing:" << endl;
    printRectangle(rect);

    return 0;
}