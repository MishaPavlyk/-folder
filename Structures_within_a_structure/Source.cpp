#include <iostream>
#include <string>

struct Address {
    std::string city;
    std::string street;
    int houseNumber;

    Address& setCity(const std::string& newCity) {
        city = newCity;
        return *this;
    }

    Address& setStreet(const std::string& newStreet) {
        street = newStreet;
        return *this;
    }

    Address& setHouseNumber(int newHouseNumber) {
        houseNumber = newHouseNumber;
        return *this;
    }

    void print() const {
        std::cout << "City: " << city << ", Street: " << street
            << ", House: " << houseNumber << "\n";
    }
};

struct Student {
    std::string name;
    int age;
    Address address; 

    Student& setName(const std::string& newName) {
        name = newName;
        return *this;
    }

    Student& setAge(int newAge) {
        age = newAge;
        return *this;
    }

    Student& setAddress(const Address& newAddress) {
        address = newAddress;
        return *this;
    }

    void print() const {
        std::cout << "Name: " << name << "\n"
            << "Age: " << age << "\n";
        std::cout << "Address: ";
        address.print();
    }
};

int main() {
    Student student;
    Address address;

    std::string city, street, name;
    int age, houseNumber;

    std::cout << "Enter student name: ";
    std::getline(std::cin, name);

    std::cout << "Enter student age: ";
    std::cin >> age;
    std::cin.ignore();

    std::cout << "Enter city: ";
    std::getline(std::cin, city);

    std::cout << "Enter street: ";
    std::getline(std::cin, street);

    std::cout << "Enter house number: ";
    std::cin >> houseNumber;

    address.setCity(city).setStreet(street).setHouseNumber(houseNumber);
    student.setName(name).setAge(age).setAddress(address);

    std::cout << "\nStudent Information:\n";
    student.print();

    return 0;
}
