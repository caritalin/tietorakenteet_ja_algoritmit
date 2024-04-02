#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <chrono>  // for measuring time

using namespace std;
using namespace std::chrono;

// Function declarations
int sequentialSearch(const vector<int>& data, int key);
vector<int> generateData(int size);

// Increment 1 - Sequential Search
void increment1() {
    int size, key;
    cout << "Enter the size of the data: ";
    cin >> size;

    vector<int> data = generateData(size);

    cout << "Enter the key value to be searched: ";
    cin >> key;

    auto start = high_resolution_clock::now();
    int result = sequentialSearch(data, key);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    } else {
        cout << "Key not found." << endl;
    }

    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
}

// Function implementations

int sequentialSearch(const vector<int>& data, int key) {
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == key) {
            return i;
        }
    }
    return -1;
}

vector<int> generateData(int size) {
    vector<int> data(size);
    for (int i = 1; i <= size * 2; i += 2) {
        data.push_back(i);
    }
    return data;
}

int main() {
    int choice;

    do {
        cout << "\n***** Menu *****" << endl;
        cout << "1. Increment 1 - Sequential Search" << endl;
        cout << "0. Exit" << endl;
        cout << "*****************" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                increment1();
                break;
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
