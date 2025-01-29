#include <iostream>
#include <string>

class Wheels {
public:
    int count;
    Wheels(int c) : count(c) {}
    void showWheels() { std::cout << "Wheels: " << count << std::endl; }
};

class Engine {
public:
    std::string type;
    Engine(std::string t) : type(t) {}
    void showEngine() { std::cout << "Engine: " << type << std::endl; }
};

class Doors {
public:
    int count;
    Doors(int c) : count(c) {}
    void showDoors() { std::cout << "Doors: " << count << std::endl; }
};

class Seats {
public:
    int count;
    Seats(int c) : count(c) {}
    void showSeats() { std::cout << "Seats: " << count << std::endl; }
};

class SteeringWheel {
public:
    int count;
    SteeringWheel(int c) : count(c) {}
    void showSteeringWheel() { std::cout << "Steering Wheels: " << count << std::endl; }
};

class Trunk {
public:
    int capacity;
    Trunk(int c) : capacity(c) {}
    void showTrunk() { std::cout << "Trunk Capacity: " << capacity << " liters" << std::endl; }
};

class Car : public Wheels, public Engine, public Doors, public Seats, public SteeringWheel, public Trunk {
public:
    std::string model;
    Car(std::string m, int w, std::string e, int d, int s, int sw, int t)
        : Wheels(w), Engine(e), Doors(d), Seats(s), SteeringWheel(sw), Trunk(t), model(m) {}

    void showCar() {
        std::cout << "Car Model: " << model << std::endl;
        showWheels();
        showEngine();
        showDoors();
        showSeats();
        showSteeringWheel();
        showTrunk();
    }
};

int main() {
    Car myCar("Tesla Model S", 4, "Electric", 4, 5, 1, 500);
    myCar.showCar();
    return 0;
}
