#include <iostream>
#include <stack>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void prime_divisors(int num) {
    std::stack<int> divisors;

    for (int i = 2; i <= num; ++i) {
        if (is_prime(i) && num % i == 0) {
            divisors.push(i);
        }
    }

    // Print divisors in descending order
    while (!divisors.empty()) {
        std::cout << divisors.top() << " ";
        divisors.pop();
    }

    std::cout << std::endl;
}

int main() {
    int num;

    // Read an integer from the user
    std::cout << "Enter an integer: ";
    std::cin >> num;

    // Print prime divisors
    std::cout << "Prime divisors in descending order: ";
    prime_divisors(num);

    return 0;
}
