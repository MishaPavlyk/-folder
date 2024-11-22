#include <iostream>
#include <string>
using namespace std;

int main() {
    string number;
    cout << "Enter a four-digit number: ";
    cin >> number;

    if (number.length() == 4 && (number.begin(), number.end(), ::isdigit)) {
        swap(number[0], number[1]);
        swap(number[2], number[3]);
        cout << "The swapped number is: " << number << endl;
    }
    else {
        cout << "Error: The number is not four digits long." << endl;
    }

    return 0;
}
