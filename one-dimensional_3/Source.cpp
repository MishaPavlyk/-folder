#include <iostream>
#include <vector>
using namespace std;

void calculatePentagonPerimeter() {
    vector<double> sides(5);
    double perimeter = 0;
    cout << "Enter the lengths of the pentagon's sides:\n";
    for (int i = 0; i < 5; ++i) {
        cin >> sides[i];
        perimeter += sides[i];
    }
    cout << "Perimeter of the pentagon: " << perimeter << endl;
}

int main() {
    calculatePentagonPerimeter();
    return 0;
}
