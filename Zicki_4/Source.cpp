#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Enter the value of a (1 <= a <= 20): ";
    cin >> a;

    if (a < 1 || a > 20) {
        cout << "Invalid input. Please enter a number between 1 and 20." << endl;
        return 1;
    }

    int product = 1;
    // Multiplying integers from a to 20
    for (int i = a; i <= 20; i++) {
        product *= i;
    }

    cout << "The product of integers from " << a << " to 20 is: " << product << endl;
    return 0;
}
