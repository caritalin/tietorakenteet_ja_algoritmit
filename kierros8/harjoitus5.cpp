#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

pair<int, double> analyzeFibonacci(int n) {
    auto start = high_resolution_clock::now();
    int result = fibonacci(n);
    auto end = high_resolution_clock::now();
    duration<double> elapsed_time = duration_cast<duration<double>>(end - start);

    return make_pair(result, elapsed_time.count());
}

int main() {
    int upper_limit = 35; // Choose a reasonable upper limit for n

    cout << "n\tFibonacci Calls\tTime\tCall Depth" << endl;
    for (int n = 0; n < upper_limit; ++n) {
        auto [result, elapsed_time] = analyzeFibonacci(n);
        cout << n << "\t" << result << "\t" << elapsed_time << "\t" << n + 1 << endl;
    }

    return 0;
}
