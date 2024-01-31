#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Forward declaration of Queue class
class Queue;

// Placeholder for the Extended_queue class
class Extended_queue {
private:
    vector<Queue> entries; // Store entries in a vector

public:
    // Append the next input character to the extended queue
    void append(char c);

    // Serve the front of the extended queue
    void serve();

    // Retrieve and print the front entry
    bool retrieve(Queue& x);

    // Get the current size of the extended queue
    int size() const;

    // Clear the extended queue
    void clear();

    // Print the extended queue
    void print() const;
};

// Placeholder for the Queue class
class Queue {
private:
    vector<char> data; // Store characters in a vector

public:
    // Append a character to the queue
    void append(char c);

    // Serve the front of the queue
    void serve();

    // Retrieve and print the front entry
    bool retrieve(Queue& q) const;

    // Get the current size of the queue
    int size() const;

    // Clear the queue
    void clear();

    friend ostream& operator<<(ostream& os, const Queue& q); // Overload << to print the queue
};

// Function declarations
void introduction();
char get_command();
void help();
bool do_command(char c, Extended_queue &test_queue);

void Extended_queue::append(char c) {
    if (entries.empty()) {
        // If entries is empty, add a new Queue
        Queue newQueue;
        newQueue.append(c);
        entries.push_back(newQueue);
    } else {
        // Append to the last Queue in entries
        entries.back().append(c);
    }
}


void Extended_queue::serve() {
    if (!entries.empty())
        entries.front().serve(); // Serve from the first Queue in entries
}

bool Extended_queue::retrieve(Queue& x) {
    if (!entries.empty()) {
        x = entries.front(); // Copy the entire Queue
        entries.erase(entries.begin()); // Remove the first Queue
        return true;
    }
    return false;
}

int Extended_queue::size() const {
    int totalSize = 0;
    for (const auto& entry : entries)
        totalSize += entry.size(); // Sum up the sizes of all Queues
    return totalSize;
}

void Extended_queue::clear() {
    entries.clear(); // Clear all Queues
}

void Extended_queue::print() const {
    for (const auto& entry : entries)
        cout << entry; // Print each Queue
}

// Queue implementation
void Queue::append(char c) {
    data.push_back(c); // Append to the end of the queue
}

void Queue::serve() {
    if (!data.empty())
        data.erase(data.begin()); // Remove the first element of the queue
}

bool Queue::retrieve(Queue& q) const {
    if (!data.empty()) {
        q = *this; // Copy the entire Queue
        return true;
    }
    return false;
}

int Queue::size() const {
    return data.size(); // Return the size of the queue
}

void Queue::clear() {
    data.clear(); // Clear the queue
}

ostream& operator<<(ostream& os, const Queue& q) {
    for (char c : q.data)
        os << c << " "; // Print each character separated by space
    return os;
}

// Other functions
void introduction() {
    cout << "Welcome to the Extended Queue Demonstration!" << endl;
    help();
}

char get_command() {
    cout << "Enter a command: ";
    char command;
    cin >> command;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    return tolower(command);
}

void help() {
    cout << "Valid commands:" << endl
         << "A - Append the next input character to the extended queue" << endl
         << "S - Serve the front of the extended queue" << endl
         << "R - Retrieve and print the front entry" << endl
         << "# - The current size of the extended queue" << endl
         << "C - Clear the extended queue (same as delete)" << endl
         << "P - Print the extended queue" << endl
         << "H - Display this help screen" << endl
         << "Q - Quit" << endl;
    cout << "Press <Enter> to continue." << flush;
    char enter;
    do {
        cin.get(enter);
    } while (enter != '\n');
}

bool do_command(char c, Extended_queue &test_queue) {
    bool continue_input = true;
    Queue entry;

    switch (c) {
        case 'a':
            char inputChar;
            cout << "Enter a character to append: ";
            cin >> inputChar;
            test_queue.append(inputChar);
            break;

        case 's':
            test_queue.serve();
            break;

        case 'r':
            if (test_queue.retrieve(entry))
                cout << "The first entry is: " << entry << endl;
            else
                cout << "Queue is empty." << endl;
            break;

        case '#':
            cout << "The current size of the extended queue is: " << test_queue.size() << endl;
            break;

        case 'c':
            test_queue.clear();
            cout << "Extended queue cleared." << endl;
            break;

        case 'p':
            cout << "Extended queue content: ";
            test_queue.print();
            cout << endl;
            break;

        case 'h':
            help();
            break;

        case 'q':
            cout << "Extended queue demonstration finished." << endl;
            continue_input = false;
            break;

        default:
            cout << "Invalid command. Enter 'H' for help." << endl;
    }

    return continue_input;
}

int main() {
    Extended_queue test_queue;
    introduction();

    while (do_command(get_command(), test_queue));

    return 0;
}
