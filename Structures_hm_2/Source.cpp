#include <iostream>
#include <string>

struct Car {
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    std::string color;
    std::string transmissionType;

    Car() : length(0), clearance(0), engineVolume(0), enginePower(0), wheelDiameter(0), color("Unknown"), transmissionType("Unknown") {}

    void setValues(double len, double cl, double vol, double power, double wheelDiam, const std::string& col, const std::string& transType) {
        length = len;
        clearance = cl;
        engineVolume = vol;
        enginePower = power;
        wheelDiameter = wheelDiam;
        color = col;
        transmissionType = transType;
    }

    void display() const {
        std::cout << "Car Specifications: \n"
                  << "Length: " << length << " meters\n"
                  << "Clearance: " << clearance << " meters\n"
                  << "Engine Volume: " << engineVolume << " liters\n"
                  << "Engine Power: " << enginePower << " horsepower\n"
                  << "Wheel Diameter: " << wheelDiameter << " inches\n"
                  << "Color: " << color << "\n"
                  << "Transmission Type: " << transmissionType << "\n";
    }

    void searchByColor(const std::string& searchColor) const {
        if (color == searchColor) {
            display();
        } else {
            std::cout << "No car found with the color " << searchColor << ".\n";
        }
    }

    void searchByPower(double searchPower) const {
        if (enginePower == searchPower) {
            display();
        } else {
            std::cout << "No car found with the engine power " << searchPower << " horsepower.\n";
        }
    }
};

int main() {
    Car car1;
    car1.setValues(4.5, 0.15, 2.0, 150, 17, "Red", "Automatic");

    Car car2;
    car2.setValues(4.2, 0.18, 1.8, 120, 16, "Blue", "Manual");

    std::cout << "Car 1 details:\n";
    car1.display();

    std::cout << "\nCar 2 details:\n";
    car2.display();

    std::cout << "\nSearching for cars with color 'Red':\n";
    car1.searchByColor("Red");

    std::cout << "\nSearching for cars with engine power 120 horsepower:\n";
    car2.searchByPower(120);

    return 0;
}
