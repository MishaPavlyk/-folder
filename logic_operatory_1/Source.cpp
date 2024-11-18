//#include <iostream>
//using namespace std;
//
//int main() {
//    int number;
//    cout << "Enter number: ";
//    cin >> number;
//
//    if (number % 2 == 0) {
//        cout << "The number is even." << endl;
//    }
//    else {
//        cout << "The number is odd." << endl;
//    }
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main() {
//    int a, b;
//    cout << "Enter two number: ";
//    cin >> a >> b;
//
//    if (a < b) {
//        cout << "A smaller number: " << a << endl;
//    }
//    else if (a > b) {
//        cout << "A smaller number: " << b << endl;
//    }
//    else {
//        cout << "The numbers are equal: " << a << endl;
//    }
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main() {
//    int number;
//    cout << "Enter number: ";
//    cin >> number;
//
//    if (number > 0) {
//        cout << "The number is positive." << endl;
//    }
//    else if (number < 0) {
//        cout << "The number is negative." << endl;
//    }
//    else {
//        cout << "The number is zero." << endl;
//    }
//
//    return 0;
//}


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
