#include <iostream>
using namespace std;

int sumInRange(int a, int b) {
    if (a > b)
        return 0;

    return a + sumInRange(a + 1, b);
}

int main() {
    int a, b;

    cout << "Enter the starting number (a): ";
    cin >> a;

    cout << "Enter the ending number (b): ";
    cin >> b;

    if (a > b) {
        cout << "Invalid range. Make sure a <= b." << endl;
    }
    else {
        cout << "The sum of numbers from " << a << " to " << b << " is: " << sumInRange(a, b) << endl;
    }

    return 0;
}
