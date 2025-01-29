#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
    string* name;
    string* surname;
    int age;
    double averageGrade;

public:
    Student(string n, string s, int a, double avg)
        : name(new string(n)), surname(new string(s)), age(a), averageGrade(avg) {}

    Student(const Student& other)
        : name(new string(*other.name)), surname(new string(*other.surname)), age(other.age), averageGrade(other.averageGrade) {}

    Student(Student&& other) noexcept
        : name(other.name), surname(other.surname), age(other.age), averageGrade(other.averageGrade) {
        other.name = nullptr;
        other.surname = nullptr;
    }

    ~Student() {
        delete name;
        delete surname;
    }

    void showInfo() const {
        cout << "Student: " << *name << " " << *surname << ", Age: " << age << ", Average Grade: " << averageGrade << endl;
    }

    double getAverageGrade() const {
        return averageGrade;
    }
};

class Aspirant : public Student {
private:
    string* thesisTopic;

public:
    Aspirant(string n, string s, int a, double avg, string thesis)
        : Student(n, s, a, avg), thesisTopic(new string(thesis)) {}

    Aspirant(const Aspirant& other)
        : Student(other), thesisTopic(new string(*other.thesisTopic)) {}

    Aspirant(Aspirant&& other) noexcept
        : Student(move(other)), thesisTopic(other.thesisTopic) {
        other.thesisTopic = nullptr;
    }

    ~Aspirant() {
        delete thesisTopic;
    }

    void showInfo() const {
        cout << "Aspirant: " << *name << " " << *surname << ", Age: " << age
            << ", Average Grade: " << averageGrade << ", Thesis Topic: " << *thesisTopic << endl;
    }

    string getThesisTopic() const {
        return *thesisTopic;
    }
};

int main() {
    string name, surname, thesisTopic;
    int age;
    double averageGrade;

    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student surname: ";
    cin >> surname;
    cout << "Enter student age: ";
    cin >> age;
    cout << "Enter student average grade: ";
    cin >> averageGrade;

    Student student(name, surname, age, averageGrade);
    student.showInfo();

    cout << "Enter aspirant thesis topic: ";
    cin.ignore();
    getline(cin, thesisTopic);

    Aspirant aspirant(name, surname, age, averageGrade, thesisTopic);
    aspirant.showInfo();

    return 0;
}
