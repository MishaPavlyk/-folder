#include <iostream>
using namespace std;

int main() {
    double L;
    cout << "Enter the circumference of the circle: ";
    cin >> L;

    const double pi = 3.14;

    double R = L / (2 * pi);

    double S = pi * R * R;

    cout << "The area of the circle is: " << S << endl;

    return 0;
}
