#include <iostream>

const int MAX_SIZE = 100; // Maximum size of the queue

class Queue {
private:
    int data[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool empty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(int value) {
        if ((rear + 1) % MAX_SIZE == front) {
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

    int retrieve() {
        if (empty()) {
            std::cout << "Queue is empty. Cannot retrieve.\n";
            return -1; // or throw an exception
        }
        return data[front];
    }
};

int main() {
    // Testing Queue
    Queue queue;
    
    std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    std::cout << "Retrieved value: " << queue.retrieve() << std::endl;
    std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
