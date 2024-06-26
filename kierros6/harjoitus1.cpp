#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

// Node struct for linked list implementation of stack
struct Node {
    double data;
    Node* next;

    Node(double val) : data(val), next(nullptr) {}
};

// Stack class using linked structure
class LinkedStack {
private:
    Node* topNode; // Pointer to the top of the stack

public:
    LinkedStack() : topNode(nullptr) {}

    ~LinkedStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(double val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    double top() const {
        if (!isEmpty()) {
            return topNode->data;
        } else {
            cerr << "Stack is empty!" << endl;
            return NAN;
        }
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }
};

// Function to check if a token is an operator
bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool isNumber(const string& token) {
    stringstream ss(token);
    double num;
    // Try to extract a number from the stringstream
    return ss >> num && ss.eof(); // Return true if extraction successful and no further characters left
}

// Function to evaluate an operation
double evaluateOperation(double operand1, double operand2, const string& op) {
    if (op == "+")
        return operand1 + operand2;
    else if (op == "-")
        return operand1 - operand2;
    else if (op == "*")
        return operand1 * operand2;
    else if (op == "/")
        return operand1 / operand2;
    else {
        cerr << "Invalid operator: " << op << endl;
        return NAN; // Not a number
    }
}

// Function to evaluate a PostFix expression
double evaluatePostFix(const string& expression) {
    LinkedStack operands; // Stack to hold operands

    stringstream ss(expression); // String stream to tokenize the expression
    string token;

    while (ss >> token) { // Tokenize the expression
        if (isNumber(token)) { // If token is a number, push it onto the stack
            operands.push(stod(token));
        } else if (isOperator(token)) { // If token is an operator
            if (operands.isEmpty()) { // Ensure there are enough operands in the stack
                cerr << "Invalid expression: insufficient operands for operator " << token << endl;
                return NAN;
            }
            // Pop the top two operands from the stack
            double operand2 = operands.top();
            operands.pop();
            if (operands.isEmpty()) { // Ensure there are enough operands in the stack
                cerr << "Invalid expression: insufficient operands for operator " << token << endl;
                return NAN;
            }
            double operand1 = operands.top();
            operands.pop();
            // Evaluate the operation and push the result onto the stack
            operands.push(evaluateOperation(operand1, operand2, token));
        } else { // If token is neither a number nor an operator
            cerr << "Invalid token: " << token << endl;
            return NAN;
        }
    }

    // At the end, there should be exactly one operand left in the stack
    if (operands.isEmpty()) {
        cerr << "Invalid expression: too many operands" << endl;
        return NAN;
    }

    // Return the final result
    return operands.top();
}

int main() {
    string expression;
    cout << "Enter a PostFix expression: ";
    getline(cin, expression);

    // Evaluate the expression and print the result
    double result = evaluatePostFix(expression);
    if (!isnan(result))
        cout << "Result: " << result << endl;

    return 0;
}
