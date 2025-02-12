#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class PriorityQueue {
private:
    struct Node {
        T value;
        int priority;
    };
    std::vector<Node> queue;
    int size;

public:
    PriorityQueue(int s) : size(s) {}

    bool IsEmpty() const {
        return queue.empty();
    }

    bool IsFull() const {
        return queue.size() >= size;
    }

    void InsertWithPriority(T value, int priority) {
        if (IsFull()) {
            std::cout << "Queue is full! Cannot insert.\n";
            return;
        }
        queue.push_back({ value, priority });
        std::sort(queue.begin(), queue.end(), [](const Node& a, const Node& b) {
            return a.priority > b.priority;
            });
    }

    void PullHighestPriorityElement() {
        if (IsEmpty()) {
            std::cout << "Queue is empty! Cannot pull.\n";
            return;
        }
        queue.erase(queue.begin());
    }

    T Peek() const {
        if (IsEmpty()) {
            std::cout << "Queue is empty! No element to peek.\n";
            return T();
        }
        return queue.front().value;
    }

    void Show() const {
        if (IsEmpty()) {
            std::cout << "Queue is empty!\n";
            return;
        }
        std::cout << "Queue elements (value, priority): ";
        for (const auto& node : queue) {
            std::cout << "(" << node.value << ", " << node.priority << ") ";
        }
        std::cout << "\n";
    }
};

int main() {
    int queueSize;
    std::cout << "Enter the size of the priority queue: ";
    std::cin >> queueSize;

    PriorityQueue<int> pq(queueSize);
    pq.InsertWithPriority(10, 2);
    pq.InsertWithPriority(20, 5);
    pq.InsertWithPriority(30, 1);
    pq.Show();
    pq.PullHighestPriorityElement();
    pq.Show();
    std::cout << "Highest priority element: " << pq.Peek() << "\n";
    pq.InsertWithPriority(40, 4);
    pq.InsertWithPriority(50, 3);
    pq.Show();
    return 0;
}
