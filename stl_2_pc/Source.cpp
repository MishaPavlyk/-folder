#include <iostream>
#include <vector>
#include <string>

struct Train {
    int number;
    std::string departureTime;
    std::string destination;
};

class TrainSchedule {
private:
    std::vector<Train> trains;
public:
    void addTrain(int number, const std::string& time, const std::string& destination) {
        trains.push_back({ number, time, destination });
    }

    void displayAllTrains() const {
        for (const auto& train : trains) {
            std::cout << "Train Number: " << train.number
                << ", Departure Time: " << train.departureTime
                << ", Destination: " << train.destination << "\n";
        }
    }

    void searchTrain(int number) const {
        bool found = false;
        for (const auto& train : trains) {
            if (train.number == number) {
                std::cout << "Train Number: " << train.number
                    << ", Departure Time: " << train.departureTime
                    << ", Destination: " << train.destination << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "Train not found.\n";
        }
    }
};

int main() {
    TrainSchedule schedule;
    schedule.addTrain(101, "08:30", "New York");
    schedule.addTrain(202, "12:45", "Los Angeles");
    schedule.addTrain(303, "16:20", "Chicago");

    std::cout << "All Trains:\n";
    schedule.displayAllTrains();

    std::cout << "\nEnter train number to search: ";
    int searchNumber;
    std::cin >> searchNumber;
    schedule.searchTrain(searchNumber);

    return 0;
}
