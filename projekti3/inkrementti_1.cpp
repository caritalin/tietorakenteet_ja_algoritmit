#include <iostream>
#include <vector>
#include <chrono>

int sequentialSearch(const std::vector<int>& data, int key) {
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == key) {
            return i;
        }
    }
    return -1; // Key not found
}

int main() {
    int size, key;
    std::cout << "Enter the size of the data: ";
    std::cin >> size;

    // Generating data with odd numbers
    std::vector<int> data;
    for (int i = 1; i <= size * 2; i += 2) {
        data.push_back(i);
    }

    std::cout << "Enter the key value to be searched: ";
    std::cin >> key;

    auto start = std::chrono::high_resolution_clock::now();

    int result = sequentialSearch(data, key);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    if (result != -1) {
        std::cout << "Key found at index: " << result << std::endl;
    } else {
        std::cout << "Key not found." << std::endl;
    }

    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
