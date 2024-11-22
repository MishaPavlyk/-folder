#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string name = "The War and the Peace";
    string author = "L.N. Tolstoj";
    string publisher = "Piter";
    int pages = 500;

    cout << setw(15) << left << "Name:" << '"' << name << '"' << endl;
    cout << setw(15) << left << "Author:" << author << endl;
    cout << setw(15) << left << "Publisher:" << publisher << endl;
    cout << setw(15) << left << "Pages:" << pages << endl;

    return 0;
}