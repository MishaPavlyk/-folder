#include <iostream>
#include <string>
using namespace std;

class Transport {
protected:
    double speed;       
    double costPerKm;    

public:
    Transport(double speed, double costPerKm) : speed(speed), costPerKm(costPerKm) {}

    virtual double calculateTime(double distance) const = 0;

    virtual double calculateCost(double distance) const = 0;

    virtual ~Transport() {}
};

class Car : public Transport {
public:
    Car(double speed, double costPerKm) : Transport(speed, costPerKm) {}

    double calculateTime(double distance) const override {
        return distance / speed;
    }

    double calculateCost(double distance) const override {
        return distance * costPerKm;
    }
};

class Bicycle : public Transport {
public:
    Bicycle(double speed, double costPerKm) : Transport(speed, costPerKm) {}

    double calculateTime(double distance) const override {
        return distance / speed;
    }

    double calculateCost(double distance) const override {
        return distance * costPerKm;
    }
};

class Cart : public Transport {
public:
    Cart(double speed, double costPerKm) : Transport(speed, costPerKm) {}

    double calculateTime(double distance) const override {
        return distance / speed;
    }

    double calculateCost(double distance) const override {
        return distance * costPerKm;
    }
};

int main() {
    double distance;
    cout << "Enter the transportation distance (km): ";
    cin >> distance;

    Car car(80, 5);           
    Bicycle bicycle(20, 1);   
    Cart cart(10, 2);         

    cout << "\nCar:\n";
    cout << "Time: " << car.calculateTime(distance) << " hours\n";
    cout << "Cost: " << car.calculateCost(distance) << " currency units\n";

    cout << "\nBicycle:\n";
    cout << "Time: " << bicycle.calculateTime(distance) << " hours\n";
    cout << "Cost: " << bicycle.calculateCost(distance) << " currency units\n";

    cout << "\nCart:\n";
    cout << "Time: " << cart.calculateTime(distance) << " hours\n";
    cout << "Cost: " << cart.calculateCost(distance) << " currency units\n";

    return 0;
}
