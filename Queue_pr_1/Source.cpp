#include <iostream>

template <typename T, int SIZE>
class Queue {
private:
    T data[SIZE];
    int front;
    int rear;
    int count;

public:
    Queue() : front(0), rear(-1), count(0) {}

    bool IsEmpty() const {
        return count == 0;
    }

    bool IsFull() const {
        return count == SIZE;
    }

    void Enqueue(T value) {
        if (IsFull()) {
            std::cout << "Queue is full! Cannot enqueue.\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        data[rear] = value;
        count++;
    }

    void Dequeue() {
        if (IsEmpty()) {
            std::cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }
        front = (front + 1) % SIZE;
        count--;
    }

    void Show() const {
        if (IsEmpty()) {
            std::cout << "Queue is empty!\n";
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = 0, index = front; i < count; i++, index = (index + 1) % SIZE) {
            std::cout << data[index] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Queue<int, 5> q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Show();
    q.Dequeue();
    q.Show();
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);
    q.Show();
    q.Enqueue(70);
    return 0;
}
