#include <iostream>
using namespace std;

int main() {
    double v, t, a;
    cout << "Enter initial velocity (v): ";
    cin >> v;
    cout << "Enter time (t): ";
    cin >> t;o
    cout << "Enter acceleration (a): ";
    cin >> a;

    double S = v * t + (a * t * t) / 2;

    cout << "The distance covered (S) is: " << S << endl;

    return 0;
}