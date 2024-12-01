#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, y;
    cout << "Enter the base number x: ";
    cin >> x;
    cout << "Enter the exponent y: ";
    cin >> y;

    int result = pow(x, y);

    cout << x << " raised to the power of " << y << " is: " << result << endl;
    return 0;
}
