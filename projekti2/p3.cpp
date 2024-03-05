#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class Airport {
private:
    int landingQueue;
    int takeoffQueue;
    int landedPlanes;
    int takeoffPlanes;
    int refusedLandings;
    int refusedTakeoffs;

public:
    Airport() : landingQueue(0), takeoffQueue(0), landedPlanes(0), takeoffPlanes(0), refusedLandings(0), refusedTakeoffs(0) {}

    void simulate(int landingRate, int takeoffRate, int timeUnits) {
        for (int i = 0; i < timeUnits; ++i) {
            if (rand() % (1 + landingRate) == 0) {
                if (landingQueue < 5) {
                    ++landingQueue;
                } else {
                    ++refusedLandings;
                    if (takeoffQueue < 5) {
                        ++takeoffQueue;
                    } else {
                        ++refusedTakeoffs;
                    }
                }
            }

            if (rand() % (1 + takeoffRate) == 0) {
                if (takeoffQueue < 5) {
                    ++takeoffQueue;
                } else {
                    ++refusedTakeoffs;
                    if (landingQueue < 5) {
                        ++landingQueue;
                    } else {
                        ++refusedLandings;
                    }
                }
            }

            if (landingQueue > 0) {
                --landingQueue;
                ++landedPlanes;
            }

            if (takeoffQueue > 0) {
                --takeoffQueue;
                ++takeoffPlanes;
            }
        }
    }

    void printResults() {
        cout << "Planes landed: " << landedPlanes << endl;
        cout << "Planes took off: " << takeoffPlanes << endl;
        cout << "Planes refused landing: " << refusedLandings << endl;
        cout << "Planes refused takeoff: " << refusedTakeoffs << endl;
    }
};

// Function to handle invalid input and clear input buffer
void handleInvalidInput() {
    cout << "Invalid input. Please enter a valid integer." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to handle out of range input
void handleOutOfRangeInput() {
    cout << "Invalid input. Please enter a value within the valid range." << endl;
}

// Main function for P1 version of the airport simulator
void main_P1() {
    srand(time(0)); // Seed the random number generator

    Airport airport;

    int landingRate, takeoffRate, timeUnits;

    // Get landing rate
    cout << "Enter landing rate per time unit: ";
    while (!(cin >> landingRate) || landingRate < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter landing rate per time unit: ";
    }

    // Get takeoff rate
    cout << "Enter takeoff rate per time unit: ";
    while (!(cin >> takeoffRate) || takeoffRate < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter takeoff rate per time unit: ";
    }

    // Get number of time units to simulate
    cout << "Enter number of time units to simulate: ";
    while (!(cin >> timeUnits) || timeUnits < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter number of time units to simulate: ";
    }

    airport.simulate(landingRate, takeoffRate, timeUnits);

    airport.printResults();
}

// Main function for P2 version of the airport simulator
void main_P2() {
    srand(time(0)); // Seed the random number generator

    Airport airport;

    int landingRate, takeoffRate, timeUnits;

    // Get landing rate for P2
    cout << "Enter landing rate per time unit for P2: ";
    while (!(cin >> landingRate) || landingRate < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter landing rate per time unit for P2: ";
    }

    // Get takeoff rate for P2
    cout << "Enter takeoff rate per time unit for P2: ";
    while (!(cin >> takeoffRate) || takeoffRate < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter takeoff rate per time unit for P2: ";
    }

    // Get number of time units to simulate for P2
    cout << "Enter number of time units to simulate for P2: ";
    while (!(cin >> timeUnits) || timeUnits < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter number of time units to simulate for P2: ";
    }

    airport.simulate(landingRate, takeoffRate, timeUnits);

    airport.printResults();
}

// Main function for P3 version of the airport simulator
void main_P3() {
    srand(time(0)); // Seed the random number generator

    Airport airport;

    int landingRate, takeoffRate, timeUnits;

    // Get landing rate for P3
    cout << "Enter landing rate per time unit for P3: ";
    while (!(cin >> landingRate) || landingRate < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter landing rate per time unit for P3: ";
    }

    // Get takeoff rate for P3
    cout << "Enter takeoff rate per time unit for P3: ";
    while (!(cin >> takeoffRate) || takeoffRate < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter takeoff rate per time unit for P3: ";
    }

    // Get number of time units to simulate for P3
    cout << "Enter number of time units to simulate for P3: ";
    while (!(cin >> timeUnits) || timeUnits < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter number of time units to simulate for P3: ";
    }

    airport.simulate(landingRate, takeoffRate, timeUnits);

    airport.printResults();
}

int main() {
    int choice;
    do {
        cout << "1. Run P1 version of Airport simulator\n"
             << "2. Run P2 version of Airport simulator\n"
             << "3. Run P3 version of Airport simulator\n"
             << "4. Run P4 version of Airport simulator\n"
             << "5. Run P5 version of Airport simulator\n"
             << "6. Quit the program\n"
             << "Your choice: ";
        while (!(cin >> choice) || choice < 1 || choice > 6) {
            if (!cin) {
                handleInvalidInput();
            } else {
                handleOutOfRangeInput();
            }
            cout << "Your choice: ";
        }

        switch (choice) {
            case 1:
                main_P1();
                break;
            case 2:
                main_P2();
                break;
            case 3:
                main_P3();
                break;
            // Implement other cases for P4 and P5 versions
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
