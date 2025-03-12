#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct Car {
    std::string name;
    int year;
    double engineVolume;
    double price;

    void display() const {
        std::cout << "Name: " << name << ", Year: " << year
            << ", Engine Volume: " << engineVolume << "L"
            << ", Price: $" << price << std::endl;
    }
};

class CarDealership {
private:
    std::vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void removeCar(const std::string& name) {
        cars.erase(std::remove_if(cars.begin(), cars.end(),
            [&name](const Car& car) { return car.name == name; }),
            cars.end());
    }

    void displayCars() const {
        for (const auto& car : cars) {
            car.display();
        }
    }

    void sortCars(std::function<bool(const Car&, const Car&)> comparator) {
        std::sort(cars.begin(), cars.end(), comparator);
    }

    void searchCars(std::function<bool(const Car&)> predicate) const {
        for (const auto& car : cars) {
            if (predicate(car)) {
                car.display();
            }
        }
    }
};

int main() {
    CarDealership dealership;
    dealership.addCar({ "Toyota Camry", 2022, 2.5, 30000 });
    dealership.addCar({ "Honda Civic", 2020, 1.8, 25000 });
    dealership.addCar({ "Ford Mustang", 2021, 5.0, 55000 });

    std::cout << "All Cars:\n";
    dealership.displayCars();

    std::cout << "\nSorted by Price:\n";
    dealership.sortCars([](const Car& a, const Car& b) { return a.price < b.price; });
    dealership.displayCars();

    std::cout << "\nCars with engine > 2.0L:\n";
    dealership.searchCars([](const Car& car) { return car.engineVolume > 2.0; });

    dealership.removeCar("Honda Civic");
    std::cout << "\nAfter Removing Honda Civic:\n";
    dealership.displayCars();

    return 0;
}