#include <iostream>
#include <string>
#include <vector>

class Person {
private:
    std::string* name;
public:
    Person(const std::string& name_) : name(new std::string(name_)) {}

    Person(const Person& other) : name(new std::string(*other.name)) {}

    Person(Person&& other) noexcept : name(other.name) {
        other.name = nullptr;
    }

    Person& operator=(Person&& other) noexcept {
        if (this != &other) {
            delete name;
            name = other.name;
            other.name = nullptr;
        }
        return *this;
    }

    ~Person() {
        delete name;
    }

    void print() const {
        std::cout << "Person: " << *name << std::endl;
    }
};

class Apartment {
private:
    std::vector<Person>* people;
public:
    Apartment() : people(new std::vector<Person>) {}

    Apartment(const Apartment& other) : people(new std::vector<Person>(*other.people)) {}

    Apartment(Apartment&& other) noexcept : people(other.people) {
        other.people = nullptr;
    }

    Apartment& operator=(Apartment&& other) noexcept {
        if (this != &other) {
            delete people;
            people = other.people;
            other.people = nullptr;
        }
        return *this;
    }

    ~Apartment() {
        delete people;
    }

    void addPerson(const Person& person) {
        people->push_back(person);
    }

    void print() const {
        std::cout << "Apartment: " << people->size() << " people" << std::endl;
        for (const auto& person : *people) {
            person.print();
        }
    }
};

class House {
private:
    std::vector<Apartment>* apartments;
public:
    House() : apartments(new std::vector<Apartment>) {}

    House(const House& other) : apartments(new std::vector<Apartment>(*other.apartments)) {}

    House(House&& other) noexcept : apartments(other.apartments) {
        other.apartments = nullptr;
    }

    House& operator=(House&& other) noexcept {
        if (this != &other) {
            delete apartments;
            apartments = other.apartments;
            other.apartments = nullptr;
        }
        return *this;
    }

    ~House() {
        delete apartments;
    }

    void addApartment(const Apartment& apartment) {
        apartments->push_back(apartment);
    }

    void print() const {
        std::cout << "House: " << apartments->size() << " apartments" << std::endl;
        for (const auto& apartment : *apartments) {
            apartment.print();
        }
    }
};

int main() {
    Person person1("Ivan");
    Person person2("Maria");

    Apartment apartment1;
    apartment1.addPerson(person1);
    apartment1.addPerson(person2);

    House house1;
    house1.addApartment(apartment1);

    House house2 = std::move(house1);

    house2.print();

    return 0;
}
