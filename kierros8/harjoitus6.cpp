#include <iostream>

using namespace std;

// (a) Non-recursive function
int gcd_iterative(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// (b) Recursive function
int gcd_recursive(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        return gcd_recursive(y, x % y);
    }
}

// (c) Iterative version of the recursive function
int gcd_recursive_to_iterative(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main() {
    int x = 48;
    int y = 36;

    cout << "GCD (iterative): " << gcd_iterative(x, y) << endl;
    cout << "GCD (recursive): " << gcd_recursive(x, y) << endl;
    cout << "GCD (recursive to iterative): " << gcd_recursive_to_iterative(x, y) << endl;

    return 0;
}
