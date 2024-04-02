#include <iostream>
#include <vector>
#include <algorithm>
#include "Timer.h" // Timer-luokan tiedosto

// Peräkkäinen haku (Sequential Search)
int sequentialSearch(const std::vector<int>& data, int key) {
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == key) {
            return i;
        }
    }
    return -1; // Key not found
}

// Binäärihaku (Binary Search)
int binarySearch(const std::vector<int>& data, int key) {
    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == key) {
            return mid; // Key found
        }
        if (data[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Key not found
}

// Generoi satunnaisia lukuja datajoukkoon
std::vector<int> generateData(int size) {
    std::vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = i + 1; // Generoi datajoukko nousevassa järjestyksessä
    }
    std::random_shuffle(data.begin(), data.end()); // Sekoita datajoukko
    return data;
}

int main() {
    int size, key;
    std::cout << "Enter the size of the data: ";
    std::cin >> size;

    std::vector<int> data = generateData(size);

    std::cout << "Enter the key value to be searched: ";
    std::cin >> key;

    Timer timer; // Luo ajastin-olion
    int result = sequentialSearch(data, key);
    double sequentialTime = timer.elapsed_time(); // Lasketaan kulunut aika peräkkäiselle haulle
    std::cout << "Sequential search result: ";
    if (result != -1) {
        std::cout << "Key found at index: " << result << std::endl;
    } else {
        std::cout << "Key not found." << std::endl;
    }

    timer.reset(); // Nollataan ajastin
    std::sort(data.begin(), data.end()); // Lajitellaan datajoukko binäärihaun vaatimassa järjestyksessä
    result = binarySearch(data, key);
    double binaryTime = timer.elapsed_time(); // Lasketaan kulunut aika binäärihaulle
    std::cout << "Binary search result: ";
    if (result != -1) {
        std::cout << "Key found at index: " << result << std::endl;
    } else {
        std::cout << "Key not found." << std::endl;
    }

    // Tulosta suorituskyvyn vertailutulokset
    std::cout << "Sequential search time: " << sequentialTime << " milliseconds" << std::endl;
    std::cout << "Binary search time: " << binaryTime << " milliseconds" << std::endl;

    return 0;
}
