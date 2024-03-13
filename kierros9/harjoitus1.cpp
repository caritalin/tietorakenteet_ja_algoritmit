#include <iostream>
#include <vector>

using namespace std;

typedef int List_entry;

enum Error_code {
    success,
    overflow,
    underflow
};

typedef vector<List_entry> List;

// E1
Error_code insert_first(const List_entry &x, List &a_list) {
    if (a_list.empty())
        return underflow; // Error: List is empty
    else {
        a_list.insert(a_list.begin(), x);
        return success;
    }
}

// E2
Error_code remove_first(List_entry &x, List &a_list) {
    if (a_list.empty())
        return underflow; // Error: List is empty
    else {
        x = a_list.front();
        a_list.erase(a_list.begin());
        return success;
    }
}

// E3
Error_code insert_last(const List_entry &x, List &a_list) {
    a_list.push_back(x);
    return success;
}

// E4
Error_code remove_last(List_entry &x, List &a_list) {
    if (a_list.empty())
        return underflow; // Error: List is empty
    else {
        x = a_list.back();
        a_list.pop_back();
        return success;
    }
}

// E5
Error_code median_list(List_entry &x, List &a_list) {
    if (a_list.empty())
        return underflow; // Error: List is empty
    else {
        int n = a_list.size();
        if (n % 2 == 1)
            x = a_list[n / 2];
        else
            x = a_list[(n / 2) - 1];
        return success;
    }
}

// E6
Error_code interchange(int pos1, int pos2, List &a_list) {
    int n = a_list.size();
    if (pos1 < 0 || pos1 >= n || pos2 < 0 || pos2 >= n)
        return underflow; // Error: Invalid positions
    else {
        swap(a_list[pos1], a_list[pos2]);
        return success;
    }
}

// E7
void reverse_traverse_list(List &a_list, void (*visit)(List_entry &)) {
    for (int i = a_list.size() - 1; i >= 0; --i)
        visit(a_list[i]);
}

// E8
Error_code copy(List &dest, List &source) {
    dest = source;
    return success;
}

// E9
Error_code join(List &list1, List &list2) {
    for (List_entry entry : list1)
        list2.push_back(entry);
    return success;
}

// E11
Error_code split(List &source, List &oddlist, List &evenlist) {
    oddlist.clear();
    evenlist.clear();
    for (int i = 0; i < source.size(); ++i) {
        if (i % 2 == 0)
            evenlist.push_back(source[i]);
        else
            oddlist.push_back(source[i]);
    }
    return success;
}

// Example usage
int main() {
    List a_list = {1, 2, 3, 4, 5};
    List_entry x;
    Error_code result = median_list(x, a_list);
    if (result == success)
        cout << "Median: " << x << endl;
    else
        cout << "Error: List is empty" << endl;
    return 0;
}
