#include <iostream>

template <typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &value) : data(value), next(nullptr) {}
    };

    Node *front;
    Node *rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    /**
     * Inserts a new element at the rear of the queue.
     * @params {T} value - a value to add to queue
     */
    void enqueue(const T &value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    /**
     * Removes the front element of the queue and returns it.
     */
    T dequeue()
    {
        if (!isEmpty())
        {
            Node *temp = front;
            T frontValue = front->data;
            front = front->next;
            delete temp;
            size--;
            return frontValue;
        }
        // Handle the case where the queue is empty
        std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
        return T(); // Return a default-constructed value for an error
    }

    /**
     * Returns the front element present in the queue without removing it.
     */
    T getFront()
    {
        if (!isEmpty())
        {
            return front->data;
        }
        // Handle the case where the queue is empty
        std::cerr << "Queue is empty. No front element to retrieve." << std::endl;
        return T(); // Return a default-constructed value for an error
    }

    /**
     * Checks for an empty queue
     * @returns boolean indicative of whether queue is empty
     */
    bool isEmpty()
    {
        return size == 0;
    }

    /**
     * Get size of queue
     * @returns size of queue
     */
    int getSize()
    {
        return size;
    }
};
