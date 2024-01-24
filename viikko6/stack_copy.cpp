#include <iostream>
#include <stack>

// Assuming ItemType is int for simplicity
typedef int ItemType;
const int SUCCESS = 0;

// Definition for Error_code
typedef int Error_code;

class Stack {
private:
    std::stack<ItemType> data;

public:
    bool is_empty() const {
        return data.empty();
    }

    void push(const ItemType& item) {
        data.push(item);
    }

    void pop(ItemType& item) {
        if (!data.empty()) {
            item = data.top();
            data.pop();
        }
    }
};

// Function to copy stack using assignment statement
Error_code copy_stack_assignment(Stack& dest, Stack& source) {
    dest = source;
    return SUCCESS;
}

// Function to copy stack using temporary stack
Error_code copy_stack_temporary(Stack& dest, Stack& source) {
    Stack temp;
    while (!source.is_empty()) {
        ItemType item;
        source.pop(item);
        dest.push(item);
        temp.push(item);  // Restore source
    }
    while (!temp.is_empty()) {
        ItemType item;
        temp.pop(item);
        source.push(item);
    }
    return SUCCESS;
}

// Friend function to copy stack
Error_code copy_stack_friend(Stack& dest, Stack& source);

class Stack;  // Forward declaration

int main() {
    Stack source;
    source.push(1);
    source.push(2);
    source.push(3);

    // Test with assignment statement
    Stack dest_assignment;
    copy_stack_assignment(dest_assignment, source);
    std::cout << "Copy using assignment statement: ";
    while (!dest_assignment.is_empty()) {
        ItemType item;
        dest_assignment.pop(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Test with temporary stack
    Stack dest_temporary;
    copy_stack_temporary(dest_temporary, source);
    std::cout << "Copy using temporary stack: ";
    while (!dest_temporary.is_empty()) {
        ItemType item;
        dest_temporary.pop(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Test with friend function
    Stack dest_friend;
    copy_stack_friend(dest_friend, source);
    std::cout << "Copy using friend function: ";
    while (!dest_friend.is_empty()) {
        ItemType item;
        dest_friend.pop(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}

Error_code copy_stack_friend(Stack& dest, Stack& source) {
    while (!source.is_empty()) {
        ItemType item;
        source.pop(item);
        dest.push(item);
    }
    return SUCCESS;
}
