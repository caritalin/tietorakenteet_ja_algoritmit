#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(const T& item) : data(item), next(nullptr) {}
};

template<typename T>
class LinkedQueue {
private:
    Node<T>* front;
    Node<T>* rear;
public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}

    // Method to check if the queue is empty
    bool empty() const {
        return front == nullptr;
    }

    // Method to retrieve the front element of the queue
    T retrieve() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return front->data;
    }

    // Destructor to deallocate memory
    ~LinkedQueue() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    // Copy constructor
    LinkedQueue(const LinkedQueue& other) : front(nullptr), rear(nullptr) {
        Node<T>* temp = other.front;
        while (temp != nullptr) {
            enqueue(temp->data);
            temp = temp->next;
        }
    }

    // Overloaded assignment operator
    LinkedQueue& operator=(const LinkedQueue& other) {
        if (this != &other) {
            // Clear current contents
            this->~LinkedQueue();
            // Copy elements
            Node<T>* temp = other.front;
            while (temp != nullptr) {
                enqueue(temp->data);
                temp = temp->next;
            }
        }
        return *this;
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
};

int main() {
    LinkedQueue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // Testing the methods
    std::cout << "Front element: " << queue.retrieve() << std::endl;
    std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;

    LinkedQueue<int> queueCopy = queue; // Copy constructor
    LinkedQueue<int> queueAssigned;
    queueAssigned = queue; // Overloaded assignment operator

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;

    std::cout << "Front element after dequeuing: " << queue.retrieve() << std::endl;

    return 0;
}
