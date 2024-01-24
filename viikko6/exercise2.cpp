#include <iostream>
#include <stack>

// Assuming ItemType is int for simplicity
typedef int Stack_entry;
const int SUCCESS = 0;
const int FULL_STACK = 1;
const int EMPTY_STACK = 2;

// Definition for Error_code
typedef int Error_code;

class Stack {
private:
    static const int MAX_SIZE = 10;  // Adjust as needed
    std::stack<Stack_entry> data;

public:
    bool is_full() const {
        return data.size() == MAX_SIZE;
    }

    bool is_empty() const {
        return data.empty();
    }

    Error_code push(const Stack_entry &item) {
        if (is_full()) {
            return FULL_STACK;
        }
        data.push(item);
        return SUCCESS;
    }

    Error_code pop_top(Stack_entry &item) {
        if (is_empty()) {
            return EMPTY_STACK;
        }
        item = data.top();
        data.pop();
        return SUCCESS;
    }

    void clear() {
        while (!data.empty()) {
            data.pop();
        }
    }

    int size() const {
        return data.size();
    }

    void delete_all(const Stack_entry &x) {
        std::stack<Stack_entry> tempStack;

        while (!data.empty()) {
            Stack_entry item = data.top();
            data.pop();

            if (item != x) {
                tempStack.push(item);
            }
        }

        // Restore the original order to the main stack
        while (!tempStack.empty()) {
            data.push(tempStack.top());
            tempStack.pop();
        }
    }
};

int main() {
    // Example usage of the functions
    Stack myStack;

    std::cout << "Is the stack full? " << (myStack.is_full() ? "Yes" : "No") << std::endl;

    Stack_entry topValue;
    Error_code popResult = myStack.pop_top(topValue);
    if (popResult == SUCCESS) {
        std::cout << "Top value removed: " << topValue << std::endl;
    } else {
        std::cout << "Failed to remove top value. Stack may be empty." << std::endl;
    }

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(2);
    myStack.push(4);
    std::cout << "Original stack: 1 2 3 2 4" << std::endl;

    std::cout << "Stack size: " << myStack.size() << std::endl;

    myStack.clear();
    std::cout << "Stack cleared. Is the stack empty? " << (myStack.is_empty() ? "Yes" : "No") << std::endl;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(2);
    myStack.push(4);
    std::cout << "Original stack: 1 2 3 2 4" << std::endl;

    myStack.delete_all(2);
    std::cout << "Stack after deleting all occurrences of 2: ";
    while (!myStack.is_empty()) {
        Stack_entry item;
        myStack.pop_top(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}
