#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(const T& item) : data(item), next(nullptr) {}
};

template<typename T>
class ExtendedQueue {
private:
    Node<T>* front;
    Node<T>* rear;
public:
    ExtendedQueue() : front(nullptr), rear(nullptr) {}

    // Method to check if the queue is empty
    bool empty() const {
        return front == nullptr;
    }

    // Method to add an element to the rear of the queue
    void enqueue(const T& item) {
        Node<T>* newNode = new Node<T>(item);
        if (empty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Method to remove and return the front element of the queue
    T dequeue() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        T item = front->data;
        Node<T>* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        return item;
    }

    // Method to clear the queue
    void clear() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    // Method to serve and retrieve the front element of the queue
    T serve_and_retrieve() {
        T item = dequeue(); // Serve by dequeuing
        enqueue(item);      // Enqueue the served item again
        return item;       // Return the served item
    }

    // Destructor to deallocate memory
    ~ExtendedQueue() {
        clear();
    }
};

int main() {
    ExtendedQueue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element: " << queue.serve_and_retrieve() << std::endl;

    queue.clear();

    std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
