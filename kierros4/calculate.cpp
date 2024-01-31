#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct StockTransaction {
    int month;
    int price;
};

int calculateCapitalGainLossFIFO(const vector<StockTransaction>& transactions) {
    queue<int> stockQueue; // FIFO data structure
    int capitalGainLoss = 0;

    for (const StockTransaction& transaction : transactions) {
        if (transaction.month == 'J' || transaction.month == 'A' || transaction.month == 'S') {
            // Buy stock
            stockQueue.push(transaction.price);
        } else if (transaction.month == 'J' || transaction.month == 'N') {
            // Sell stock
            if (!stockQueue.empty()) {
                capitalGainLoss += transaction.price - stockQueue.front();
                stockQueue.pop();
            }
        }
    }

    return capitalGainLoss;
}

int calculateCapitalGainLossLIFO(const vector<StockTransaction>& transactions) {
    stack<int> stockStack; // LIFO data structure
    int capitalGainLoss = 0;

    for (const StockTransaction& transaction : transactions) {
        if (transaction.month == 'J' || transaction.month == 'A' || transaction.month == 'S') {
            // Buy stock
            stockStack.push(transaction.price);
        } else if (transaction.month == 'J' || transaction.month == 'N') {
            // Sell stock
            if (!stockStack.empty()) {
                capitalGainLoss += transaction.price - stockStack.top();
                stockStack.pop();
            }
        }
    }

    return capitalGainLoss;
}

int main() {
    vector<StockTransaction> transactions = {
        {'J', 10}, {'A', 30}, {'J', 20},
        {'S', 50}, {'N', 30}, {'A', 10},
        {'S', 30}
    };

    int fifoResult = calculateCapitalGainLossFIFO(transactions);
    int lifoResult = calculateCapitalGainLossLIFO(transactions);

    cout << "FIFO Capital Gain/Loss: $" << fifoResult << endl;
    cout << "LIFO Capital Gain/Loss: $" << lifoResult << endl;

    return 0;
}
