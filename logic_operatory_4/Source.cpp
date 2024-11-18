#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two number: ";
    cin >> a >> b;

    if (a == b) {
        cout << "The numbers are equal." << endl;
    }
    else {
        if (a < b) {
            cout << "The numbers are in ascending order: " << a << ", " << b << endl;
        }
        else {
            cout << "The numbers are in ascending order: " << b << ", " << a << endl;
        }
    }

    return 0;
}
