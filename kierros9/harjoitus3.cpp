#include <iostream>

using namespace std;

// Singly Linked Node
template <class T>
class SNode {
public:
    T data;
    SNode<T>* next;

    // Constructors
    SNode() : next(nullptr) {}
    SNode(const T& item, SNode<T>* next_node = nullptr) : data(item), next(next_node) {}
};

// Doubly Linked Node
template <class T>
class DNode {
public:
    T data;
    DNode<T>* next;
    DNode<T>* prev;

    // Constructors
    DNode() : next(nullptr), prev(nullptr) {}
    DNode(const T& item, DNode<T>* next_node = nullptr, DNode<T>* prev_node = nullptr) : data(item), next(next_node), prev(prev_node) {}
};

// Usage
int main() {
    // Singly Linked Node
    SNode<int>* s_node = new SNode<int>(5);
    cout << "Singly Linked Node data: " << s_node->data << endl;
    delete s_node;

    // Doubly Linked Node
    DNode<int>* d_node = new DNode<int>(10);
    cout << "Doubly Linked Node data: " << d_node->data << endl;
    delete d_node;

    return 0;
}
