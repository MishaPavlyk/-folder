#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two number: ";
    cin >> a >> b;

    if (a < b) {
        cout << "A smaller number: " << a << endl;
    }
    else if (a > b) {
        cout << "A smaller number: " << b << endl;
    }
    else {
        cout << "The numbers are equal: " << a << endl;
    }

    return 0;
}