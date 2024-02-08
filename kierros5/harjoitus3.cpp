#include <iostream>
#include <queue>
#include <string>

char analyzeInput(const std::string& line) {
    std::queue<char> leftPart;
    std::queue<char> rightPart;

    bool colonFound = false;

    // Read characters into leftPart until colon is encountered
    for (char c : line) {
        if (c == ':') {
            colonFound = true;
            continue;
        }

        if (!colonFound) {
            leftPart.push(c);
        } else {
            rightPart.push(c);
        }
    }

    // Case: No colon on the line
    if (!colonFound) {
        return 'N';
    }

    // Calculate lengths of left and right parts
    int leftLength = leftPart.size();
    int rightLength = rightPart.size();

    // Case: Left part longer than the right
    if (leftLength > rightLength) {
        return 'L';
    }

    // Case: Right part longer than the left
    if (rightLength > leftLength) {
        return 'R';
    }

    // Case: Left and right parts have the same length
    if (leftLength == rightLength) {
        // Compare the contents of left and right parts
        while (!leftPart.empty()) {
            char leftChar = leftPart.front();
            char rightChar = rightPart.front();
            leftPart.pop();
            rightPart.pop();

            if (leftChar != rightChar) {
                return 'D'; // Different
            }
        }
        return 'S'; // Same
    }

    return 'N'; // Default case
}

int main() {
    std::cout << "Enter input line: ";
    std::string line;
    std::getline(std::cin, line);

    char result = analyzeInput(line);
    std::cout << "Output: " << result << std::endl;

    return 0;
}
