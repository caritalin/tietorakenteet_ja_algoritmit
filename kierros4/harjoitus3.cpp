#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Custom Stack class
template <typename T>
class Stack {
private:
    std::stack<T> data;

public:
    bool isEmpty() const {
        return data.empty();
    }

    void push(const T& value) {
        data.push(value);
    }

    bool pop(T& value) {
        if (!isEmpty()) {
            value = data.top();
            data.pop();
            return true;
        }
        return false;
    }
};

// Custom Queue class
template <typename T>
class Queue {
private:
    std::queue<T> data;

public:
    bool isEmpty() const {
        return data.empty();
    }

    void enqueue(const T& value) {
        data.push(value);
    }

    bool dequeue(T& value) {
        if (!isEmpty()) {
            value = data.front();
            data.pop();
            return true;
        }
        return false;
    }
};

// (a) Move all entries from a Stack into a Queue
template <typename T>
void moveStackToQueue(Stack<T>& stack, Queue<T>& queue) {
    while (!stack.isEmpty()) {
        T value;
        stack.pop(value);
        queue.enqueue(value);
    }
}

// (b) Move all entries from a Queue onto a Stack
template <typename T>
void moveQueueToStack(Queue<T>& queue, Stack<T>& stack) {
    while (!queue.isEmpty()) {
        T value;
        queue.dequeue(value);
        stack.push(value);
    }
}

// (c) Empty one Stack onto the top of another Stack (preserve order)
template <typename T>
void emptyStackToStackPreserveOrder(Stack<T>& source, Stack<T>& destination) {
    Stack<T> tempStack;

    while (!source.isEmpty()) {
        T value;
        source.pop(value);
        tempStack.push(value);
    }

    while (!tempStack.isEmpty()) {
        T value;
        tempStack.pop(value);
        destination.push(value);
    }
}

// (d) Empty one Stack onto the top of another Stack (reverse order)
template <typename T>
void emptyStackToStackReverseOrder(Stack<T>& source, Stack<T>& destination) {
    Stack<T> tempStack;

    while (!source.isEmpty()) {
        T value;
        source.pop(value);
        tempStack.push(value);
    }

    while (!tempStack.isEmpty()) {
        T value;
        tempStack.pop(value);
        destination.push(value);
    }
}

// (e) Use a local Stack to reverse the order of all entries in a Queue
template <typename T>
void reverseOrderOfQueue(Queue<T>& queue) {
    Stack<T> tempStack;

    while (!queue.isEmpty()) {
        T value;
        queue.dequeue(value);
        tempStack.push(value);
    }

    while (!tempStack.isEmpty()) {
        T value;
        tempStack.pop(value);
        queue.enqueue(value);
    }
}

// (f) Use a local Queue to reverse the order of all entries in a Stack
template <typename T>
void reverseOrderOfStack(Stack<T>& stack) {
    Queue<T> tempQueue;

    while (!stack.isEmpty()) {
        T value;
        stack.pop(value);
        tempQueue.enqueue(value);
    }

    while (!tempQueue.isEmpty()) {
        T value;
        tempQueue.dequeue(value);
        stack.push(value);
    }
}

int main() {
    // Example usage
    Stack<int> stack;
    Queue<int> queue;

    for (int i = 1; i <= 5; ++i) {
        stack.push(i);
        queue.enqueue(i);
    }

    cout << "Original Stack: ";
    while (!stack.isEmpty()) {
        int value;
        stack.pop(value);
        cout << value << " ";
    }
    cout << endl;

    cout << "Original Queue: ";
    while (!queue.isEmpty()) {
        int value;
        queue.dequeue(value);
        cout << value << " ";
    }
    cout << endl;

    moveStackToQueue(stack, queue);

    cout << "Stack after moving to Queue: ";
    while (!stack.isEmpty()) {
        int value;
        stack.pop(value);
        cout << value << " ";
    }
    cout << endl;

    cout << "Queue after moving to Stack: ";
    while (!queue.isEmpty()) {
        int value;
        queue.dequeue(value);
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
