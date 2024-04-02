#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // for atoi function
#include <cctype> // for isdigit function

// Function to check if a string is a positive integer
bool isPositiveInteger(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false; // Not a digit
        }
    }
    return true;
}

int main() {
    std::string input;
    int size;

    while (true) {
        std::cout << "Enter the size of the data to be sorted: ";
        std::cin >> input;

        if (!isPositiveInteger(input)) {
            std::cout << "Invalid input. Please enter a positive number.\n";
            continue;
        }

        size = std::atoi(input.c_str()); // Convert string to integer
        if (size <= 0) {
            std::cout << "Invalid size. Please enter a positive number.\n";
        } else {
            break; // Valid input, exit loop
        }
    }

    // Generate data and perform sorting
    std::vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 10000; // Generate random numbers between 0 and 9999
    }

    // Print first 10 elements of unsorted data
    std::cout << "First 10 elements of the data:" << std::endl;
    for (int i = 0; i < 10 && i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    // Sort the data
    std::sort(data.begin(), data.end());

    // Print first 10 elements of sorted data
    std::cout << "First 10 elements of the data after sorting:" << std::endl;
    for (int i = 0; i < 10 && i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
