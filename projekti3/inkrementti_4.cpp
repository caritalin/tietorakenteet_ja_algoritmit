#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <limits>  // numeric_limits

using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap current element with index
        }
    }
    swap(arr[i + 1], arr[high]); // Swap pivot element with the element at index i + 1
    return i + 1;
}

// Function to perform quicksort recursively
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the elements of the array
void printArray(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Seed for random number generation
    srand(time(0));

    // Generate random data to be sorted
    vector<int> data;
    int size;
    cout << "Enter the size of the data to be sorted: ";

    // Check if the input is a valid integer
    while (!(cin >> size)) {
        cout << "Invalid input. Please enter a valid integer." << endl;
        cin.clear();                // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    // Fill the vector with random integers
    for (int i = 0; i < size; i++) {
        data.push_back(rand() % 100); // Random numbers between 0 and 99
    }

    // Print unsorted data
    cout << "Unsorted data:" << endl;
    printArray(data);

    // Sort the data using quicksort
    quickSort(data, 0, size - 1);

    // Print sorted data
    cout << "Sorted data:" << endl;
    printArray(data);

    return 0;
}
