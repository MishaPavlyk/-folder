#include <iostream>
#include <queue>
#include <string>
#include <chrono>

struct PrintJob {
    std::string user;
    int priority;
    double time_submitted;

    bool operator<(const PrintJob& other) const {
        return priority < other.priority;
    }
};

class PrinterQueue {
private:
    std::priority_queue<PrintJob> print_queue;
    std::queue<std::string> print_log;
    double current_time = 0.0;

public:
    void addJob(const std::string& user, int priority) {
        print_queue.push({ user, priority, current_time });
        current_time += 1.0;
    }

    void processJobs() {
        while (!print_queue.empty()) {
            PrintJob job = print_queue.top();
            print_queue.pop();
            std::string log_entry = "User: " + job.user + " | Priority: " + std::to_string(job.priority) + " | Time: " + std::to_string(job.time_submitted);
            print_log.push(log_entry);
            std::cout << "Printing: " << log_entry << std::endl;
        }
    }

    void printStatistics() {
        std::cout << "\nPrint Job Statistics:" << std::endl;
        while (!print_log.empty()) {
            std::cout << print_log.front() << std::endl;
            print_log.pop();
        }
    }
};

int main() {
    PrinterQueue printer;
    printer.addJob("Alice", 2);
    printer.addJob("Bob", 1);
    printer.addJob("Charlie", 3);

    printer.processJobs();
    printer.printStatistics();
    return 0;
}
