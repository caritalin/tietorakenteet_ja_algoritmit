template<typename T>
class ExtendedQueue : public LinkedQueue<T> {
public:
    // Check if the queue is full
    bool full() const {
        // For a linked implementation, there's no fixed capacity
        // So, it's typically not "full" unless memory is exhausted
        try {
            // Attempt to allocate memory for a new node
            Node<T>* temp = new Node<T>(T());
            delete temp; // Deallocate immediately after allocation
            return false; // If allocation succeeded, queue is not full
        } catch (std::bad_alloc&) {
            return true; // If allocation failed, queue is full
        }
    }
};
