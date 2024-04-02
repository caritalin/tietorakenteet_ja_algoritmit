#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <algorithm> // sort()
#include <chrono>  // for measuring time
#include <limits>  // for numeric_limits

using namespace std;
using namespace std::chrono;

// Function declarations
int sequentialSearch(const vector<int>& data, int key);
int binarySearch(const vector<int>& data, int key);
void selectionSort(vector<int>& arr);
int partition(vector<int>& arr, int low, int high);
void quickSort(vector<int>& arr, int low, int high);
void printArray(const vector<int>& arr);
bool isPositiveInteger(const string& str);
vector<int> generateData(int size);

// Increment 1 - Sequential Search
void increment1() {
    int size, key;
    cout << "Enter the size of the data: ";
    if (!(cin >> size) || size <= 0) {
        cout << "Invalid input. Size must be a positive integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    vector<int> data;
    for (int i = 1; i <= size * 2; i += 2) {
        data.push_back(i);
    }

    cout << "Enter the key value to be searched: ";
    if (!(cin >> key)) {
        cout << "Invalid input. Please enter a valid integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

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

// Increment 2 - Sequential Search and Binary Search
void increment2() {
    int size, key;
    cout << "Enter the size of the data: ";
    if (!(cin >> size) || size <= 0) {
        cout << "Invalid input. Size must be a positive integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    vector<int> data = generateData(size);

    cout << "Enter the key value to be searched: ";
    if (!(cin >> key)) {
        cout << "Invalid input. Please enter a valid integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    auto start = high_resolution_clock::now();
    int result = sequentialSearch(data, key);
    double sequentialTime = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();

    cout << "Sequential search result: ";
    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    } else {
        cout << "Key not found." << endl;
    }

    start = high_resolution_clock::now();
    sort(data.begin(), data.end());
    result = binarySearch(data, key);
    double binaryTime = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();

    cout << "Binary search result: ";
    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    } else {
        cout << "Key not found." << endl;
    }

    cout << "Sequential search time: " << sequentialTime << " milliseconds" << endl;
    cout << "Binary search time: " << binaryTime << " milliseconds" << endl;
}

// Increment 3 - Sorting Data
void increment3() {
    string input;
    int size;

    while (true) {
        cout << "Enter the size of the data to be sorted: ";
        cin >> input;

        if (!isPositiveInteger(input)) {
            cout << "Invalid input. Please enter a positive integer." << endl;
            continue;
        }

        size = stoi(input);
        if (size <= 0) {
            cout << "Invalid size. Please enter a positive number." << endl;
        } else {
            break;
        }
    }

    vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 10000;
    }

    cout << "First 10 elements of the data:" << endl;
    printArray(data);

    sort(data.begin(), data.end());

    cout << "First 10 elements of the data after sorting:" << endl;
    printArray(data);
}

// Increment 4 - Quicksort
void increment4() {
    vector<int> data;
    int size;
    cout << "Enter the size of the data to be sorted: ";

    while (!(cin >> size) || size <= 0) {
        cout << "Invalid input. Please enter a valid positive integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < size; i++) {
        data.push_back(rand() % 100);
    }

    cout << "Unsorted data:" << endl;
    printArray(data);

    quickSort(data, 0, size - 1);

    cout << "Sorted data:" << endl;
    printArray(data);
}

// Increment 5 - Selection Sort
void increment5() {
    vector<int> data;
    int size;
    cout << "Enter the size of the data to be sorted: ";
    if (!(cin >> size) || size <= 0) {
        cout << "Invalid input. Size must be a positive integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < size; ++i) {
        int element;
        cout << "Enter element " << i+1 << ": ";
        if (!(cin >> element)) {
            cout << "Invalid input. Please enter valid integers." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        data.push_back(element);
    }

    cout << "Unsorted data:" << endl;
    printArray(data);

    auto start = high_resolution_clock::now();
    selectionSort(data);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Sorted data:" << endl;
    printArray(data);

    cout << "Time taken for selection sort: " << duration.count() << " milliseconds" << endl;
}

// Main function with menu
int main() {
    srand(time(0));
    int choice;
    
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Increment 1 - Sequential Search" << endl;
        cout << "2. Increment 2 - Sequential and Binary Search" << endl;
        cout << "3. Increment 3 - Sorting Data" << endl;
        cout << "4. Increment 4 - Quicksort" << endl;
        cout << "5. Increment 5 - Selection Sort" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                increment1();
                break;
            case 2:
                increment2();
                break;
            case 3:
                increment3();
                break;
            case 4:
                increment4();
                break;
            case 5:
                increment5();
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from the menu." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
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

int binarySearch(const vector<int>& data, int key) {
    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == key) {
            return mid;
        }
        if (data[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; ++i) {
        int min_index = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

bool isPositiveInteger(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

vector<int> generateData(int size) {
    vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = i + 1;
    }
    random_shuffle(data.begin(), data.end());
    return data;
}
