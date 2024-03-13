#include <iostream>
#include <vector>

using namespace std;

const int MAX_LIST = 100; // maximum size for the list

typedef int List_entry;

enum Error_code {
    success,
    overflow,
    underflow
};

class List {
public:
    // Constructor
    List() {
        count = 0;
    }

    // Destructor
    ~List() {}

    // Operations
    Error_code insert(int position, const List_entry &x);
    Error_code remove(int position);
    Error_code replace(int position, const List_entry &x);
    Error_code retrieve(int position, List_entry &x) const;
    bool empty() const;
    bool full() const;
    void clear();

private:
    int count; // number of elements in the list
    List_entry entry[MAX_LIST]; // array to store elements
};

// (a) Constructor
// Already implemented inline above

// (b) Clear
void List::clear() {
    count = 0;
}

// (c) Empty
bool List::empty() const {
    return count == 0;
}

// (d) Full
bool List::full() const {
    return count == MAX_LIST;
}

// (e) Replace
Error_code List::replace(int position, const List_entry &x) {
    if (position < 0 || position >= count)
        return underflow; // Error: Invalid position
    else {
        entry[position] = x;
        return success;
    }
}

// (f) Retrieve
Error_code List::retrieve(int position, List_entry &x) const {
    if (position < 0 || position >= count)
        return underflow; // Error: Invalid position
    else {
        x = entry[position];
        return success;
    }
}

// (g) Remove
Error_code List::remove(int position) {
    if (position < 0 || position >= count)
        return underflow; // Error: Invalid position
    else {
        for (int i = position; i < count - 1; ++i)
            entry[i] = entry[i + 1];
        count--;
        return success;
    }
}

// (h) Insert
Error_code List::insert(int position, const List_entry &x) {
    if (full())
        return overflow; // Error: List is full
    if (position < 0 || position > count)
        return underflow; // Error: Invalid position
    for (int i = count; i > position; --i)
        entry[i] = entry[i - 1];
    entry[position] = x;
    count++;
    return success;
}

// Usage
int main() {
    List my_list;
    for (int i = 0; i < 5; ++i)
        my_list.insert(i, i + 1);
    List_entry x;
    Error_code result = my_list.retrieve(2, x);
    if (result == success)
        cout << "Element at position 2: " << x << endl;
    else
        cout << "Error: Invalid position" << endl;
    return 0;
}
