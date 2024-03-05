#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

struct Move {
    int disk;
    char from;
    char to;
    char using_rod;
};

void removed_hanoi(int n, char A, char B, char C) {
    stack<Move> s;
    s.push({n, A, B, C});
    while (!s.empty()) {
        Move current_move = s.top();
        s.pop();
        int disk = current_move.disk;
        char from = current_move.from;
        char to = current_move.to;
        char using_rod = current_move.using_rod;
        if (disk == 1) {
            cout << "Move disk 1 from rod " << from << " to rod " << to << endl;
        } else {
            s.push({disk - 1, using_rod, from, to});
            s.push({1, from, to, using_rod});
            s.push({disk - 1, from, to, using_rod});
        }
    }
}

int main() {
    int n = 3; // Number of disks
    removed_hanoi(n, 'A', 'B', 'C');
    return 0;
}
