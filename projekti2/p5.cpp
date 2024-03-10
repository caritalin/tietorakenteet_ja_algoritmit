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

    void simulate_P1(int landingRate, int takeoffRate, int timeUnits) {
        srand(time(0)); // Seed the random number generator

        for (int i = 0; i < timeUnits; ++i) {
            if (rand() % (1 + landingRate) == 0) {
                if (landingQueue < 5) {
                    ++landingQueue;
                } else {
                    ++refusedLandings;
                }
            }

            if (rand() % (1 + takeoffRate) == 0) {
                if (takeoffQueue < 5) {
                    ++takeoffQueue;
                } else {
                    ++refusedTakeoffs;
                }
            }

            if (landingQueue > 0) {
                --landingQueue;
                ++landedPlanes;
            } else if (takeoffQueue > 0) {
                --takeoffQueue;
                ++takeoffPlanes;
            }
        }
    }

    void simulate_P2(int landingRate, int takeoffRate, int timeUnits) {
        srand(time(0)); // Seed the random number generator

        // Implement simulation for P2
    }

    void simulate_P3(int landingRate, int takeoffRate, int timeUnits) {
        srand(time(0)); // Seed the random number generator

        // Implement simulation for P3
    }

    void simulate_P4(int landingRate, int takeoffRate, int timeUnits) {
        srand(time(0)); // Seed the random number generator

        // Implement simulation for P4
    }

    void simulate_P5(int landingRate, int takeoffRate, int timeUnits) {
        srand(time(0)); // Seed the random number generator

        for (int i = 0; i < timeUnits; ++i) {
            if (rand() % (1 + landingRate) == 0) {
                if (landingQueue < 5) {
                    ++landingQueue;
                } else {
                    ++refusedLandings;
                }
            }

            if (rand() % (1 + takeoffRate) == 0) {
                if (takeoffQueue < 5) {
                    ++takeoffQueue;
                } else {
                    ++refusedTakeoffs;
                }
            }

            if (landingQueue > 0) {
                --landingQueue;
                ++landedPlanes;
            } else if (takeoffQueue > 0) {
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

    // Get landing rate for P1
    cout << "Enter landing rate per time unit for P1: ";
    while (!(cin >> landingRate) || landingRate < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter landing rate per time unit for P1: ";
    }

    // Get takeoff rate for P1
    cout << "Enter takeoff rate per time unit for P1: ";
    while (!(cin >> takeoffRate) || takeoffRate < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter takeoff rate per time unit for P1: ";
    }

    // Get number of time units to simulate for P1
    cout << "Enter number of time units to simulate for P1: ";
    while (!(cin >> timeUnits) || timeUnits < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter number of time units to simulate for P1: ";
    }

    airport.simulate_P1(landingRate, takeoffRate, timeUnits);

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

    airport.simulate_P2(landingRate, takeoffRate, timeUnits);

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

    airport.simulate_P3(landingRate, takeoffRate, timeUnits);

    airport.printResults();
}

// Main function for P4 version of the airport simulator
void main_P4() {
    srand(time(0)); // Seed the random number generator

    Airport airport;

    int landingRate, takeoffRate, timeUnits;

    // Get landing rate for P4
    cout << "Enter landing rate per time unit for P4: ";
    while (!(cin >> landingRate) || landingRate < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter landing rate per time unit for P4: ";
    }

    // Get takeoff rate for P4
    cout << "Enter takeoff rate per time unit for P4: ";
    while (!(cin >> takeoffRate) || takeoffRate < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter takeoff rate per time unit for P4: ";
    }

    // Get number of time units to simulate for P4
    cout << "Enter number of time units to simulate for P4: ";
    while (!(cin >> timeUnits) || timeUnits < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter number of time units to simulate for P4: ";
    }

    airport.simulate_P4(landingRate, takeoffRate, timeUnits);

    airport.printResults();
}

// Main function for P5 version of the airport simulator
void main_P5() {
    srand(time(0)); // Seed the random number generator

    Airport airport;

    int landingRate, takeoffRate, timeUnits;

    // Get landing rate for P5
    cout << "Enter landing rate per time unit for P5: ";
    while (!(cin >> landingRate) || landingRate < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter landing rate per time unit for P5: ";
    }

    // Get takeoff rate for P5
    cout << "Enter takeoff rate per time unit for P5: ";
    while (!(cin >> takeoffRate) || takeoffRate < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter takeoff rate per time unit for P5: ";
    }

    // Get number of time units to simulate for P5
    cout << "Enter number of time units to simulate for P5: ";
    while (!(cin >> timeUnits) || timeUnits < 0) {
        if (!cin) {
            handleInvalidInput();
        } else {
            handleOutOfRangeInput();
        }
        cout << "Enter number of time units to simulate for P5: ";
    }

    airport.simulate_P5(landingRate, takeoffRate, timeUnits);

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
            case 4:
                main_P4();
                break;
            case 5:
                main_P5();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
