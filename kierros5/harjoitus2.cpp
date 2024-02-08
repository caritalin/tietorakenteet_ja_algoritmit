#include <iostream>

const int MAX_SIZE = 100; // Maximum size of the queue

class ExtendedQueue {
private:
    int data[MAX_SIZE];
    int front, rear;

public:
    ExtendedQueue() {
        front = -1;
        rear = -1;
    }

    bool empty() {
        return (front == -1 && rear == -1);
    }

    bool full() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int value) {
        if (full()) {
            std::cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (empty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        data[rear] = value;
    }

    int dequeue() {
        if (empty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return -1; // or throw an exception
        }
        int value = data[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return value;
    }

    void clear() {
        front = rear = -1;
    }

    int serve_and_retrieve() {
        int value = dequeue();
        if (value != -1)
            return value;
        else {
            std::cout << "Error: Cannot serve and retrieve from an empty queue.\n";
            return -1; // or throw an exception
        }
    }
};

int main() {
    // Testing ExtendedQueue
    ExtendedQueue exQueue;

    std::cout << "Is extended queue empty? " << (exQueue.empty() ? "Yes" : "No") << std::endl;
    exQueue.enqueue(100);
    exQueue.enqueue(200);
    exQueue.enqueue(300);
    std::cout << "Is extended queue full? " << (exQueue.full() ? "Yes" : "No") << std::endl;
    std::cout << "Serving and retrieving value: " << exQueue.serve_and_retrieve() << std::endl;
    exQueue.clear();
    std::cout << "Is extended queue empty? " << (exQueue.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
