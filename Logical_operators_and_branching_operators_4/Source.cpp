#include <iostream>
using namespace std;

int main() {
    int distanceAB, distanceBC, weight;
    cout << "Enter the distance from A to B: ";
    cin >> distanceAB;
    cout << "Enter the distance from B to C: ";
    cin >> distanceBC;
    cout << "Enter the cargo weight (kg): ";
    cin >> weight;

    int fuelConsumption;

    // Determine fuel consumption based on weight
    if (weight <= 500) {
        fuelConsumption = 1;
    }
    else if (weight <= 1000) {
        fuelConsumption = 4;
    }
    else if (weight <= 1500) {
        fuelConsumption = 7;
    }
    else if (weight <= 2000) {
        fuelConsumption = 9;
    }
    else {
        cout << "Error: The plane cannot carry more than 2000 kg." << endl;
        return 0;
    }

    // Calculate fuel required for each leg
    int fuelRequiredAB = distanceAB * fuelConsumption;
    int fuelRequiredBC = distanceBC * fuelConsumption;

    // Check if the plane can fly from A to B and B to C
    if (fuelRequiredAB > 300) {
        cout << "Error: The plane cannot reach B with the given weight and distance." << endl;
        return 0;
    }
    if (fuelRequiredBC > 300) {
        cout << "Error: The plane cannot reach C from B with the given weight and distance." << endl;
        return 0;
    }

    // Calculate total fuel used and additional refuel needed at B
    int totalFuelUsed = fuelRequiredAB + fuelRequiredBC;
    int fuelNeededForRefuel = max(0, fuelRequiredBC - (300 - fuelRequiredAB));

    // Output results
    cout << "Fuel required for A to B: " << fuelRequiredAB << " liters" << endl;
    cout << "Fuel required for B to C: " << fuelRequiredBC << " liters" << endl;
    cout << "Total fuel used: " << totalFuelUsed << " liters" << endl;
    cout << "Minimum fuel needed for refueling at B: " << fuelNeededForRefuel << " liters" << endl;

    return 0;
}
