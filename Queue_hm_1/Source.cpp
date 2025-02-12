#include <iostream>
#include <queue>
#include <random>
#include <chrono>

struct Passenger {
    double arrival_time;
};

class BusStop {
private:
    std::queue<Passenger> queue;
    double avg_passenger_interval;
    double avg_bus_interval;
    int max_capacity;
    bool is_terminal;
    std::default_random_engine generator;
    std::exponential_distribution<double> passenger_dist;
    std::exponential_distribution<double> bus_dist;
    std::uniform_int_distribution<int> bus_capacity_dist;

public:
    BusStop(double passenger_interval, double bus_interval, int max_cap, bool terminal)
        : avg_passenger_interval(passenger_interval), avg_bus_interval(bus_interval),
        max_capacity(max_cap), is_terminal(terminal),
        generator(std::chrono::system_clock::now().time_since_epoch().count()),
        passenger_dist(1.0 / passenger_interval), bus_dist(1.0 / bus_interval),
        bus_capacity_dist(5, 15) {}

    void simulate(int total_time) {
        double current_time = 0.0;
        double next_passenger_time = passenger_dist(generator);
        double next_bus_time = bus_dist(generator);
        double total_wait_time = 0.0;
        int total_passengers = 0;

        while (current_time < total_time) {
            if (next_passenger_time < next_bus_time) {
                current_time = next_passenger_time;
                queue.push({ current_time });
                total_passengers++;
                next_passenger_time = current_time + passenger_dist(generator);
            }
            else {
                current_time = next_bus_time;
                int bus_capacity = bus_capacity_dist(generator);
                while (!queue.empty() && bus_capacity > 0) {
                    total_wait_time += (current_time - queue.front().arrival_time);
                    queue.pop();
                    bus_capacity--;
                }
                next_bus_time = current_time + bus_dist(generator);
            }
        }

        double avg_wait_time = total_passengers > 0 ? total_wait_time / total_passengers : 0;
        std::cout << "Average waiting time per passenger: " << avg_wait_time << " min.\n";
    }
};

int main() {
    double passenger_interval, bus_interval;
    int max_people;
    bool is_terminal;

    std::cout << "Enter the average time between passenger arrivals: ";
    std::cin >> passenger_interval;
    std::cout << "Enter the average time between bus arrivals: ";
    std::cin >> bus_interval;
    std::cout << "Enter the maximum number of people at the stop: ";
    std::cin >> max_people;
    std::cout << "Is the stop a terminal? (1 - yes, 0 - no): ";
    std::cin >> is_terminal;

    BusStop stop(passenger_interval, bus_interval, max_people, is_terminal);
    stop.simulate(600);

    return 0;
}
