#include <iostream>

void basic_hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        std::cout << "Move disk 1 from rod " << A << " to rod " << C << std::endl;
        return;
    }
    basic_hanoi(n - 1, A, C, B);
    std::cout << "Move disk " << n << " from rod " << A << " to rod " << C << std::endl;
    basic_hanoi(n - 1, B, A, C);
}

int main() {
    int n = 3; // Number of disks
    basic_hanoi(n, 'A', 'B', 'C');
    return 0;
}
