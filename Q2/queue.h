#include <iostream>

using namespace std;

template <typename T> struct Node
    {
        T data;
        Node *next;
        Node(const T &value) : data(value), next(nullptr) {}
    };

template <typename T>
class Queue
{
private:
    Node<T> *front;
    Node<T> *rear;
    int size;

public:
    Queue() {
      front = nullptr;
      rear = nullptr;
      size = 0;
    }

    /**
     * Inserts a new element at the rear of the queue.
     * @params {T} value - a value to add to queue
     */
    void enqueue(const T &value)
    {
        Node<T>* newNode = new Node<T>(value);
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
     * @returns front element of queue.
     */
    T dequeue()
    {
        if (!isEmpty())
        {
            Node<T>* temp = front;
            T frontValue = front->data;
            front = front->next;
            delete temp;
            size--;
            return frontValue;
        }
        // Handle the case where the queue is empty
        throw runtime_error("elements can not be dequeued from an empty queue");
        return T(); // Return a default-constructed value for an error
    }

    /**
     * Returns the front element present in the queue without removing it.
     * @returns front element of queue.
     */
    T getFront()
    {
        if (!isEmpty())
        {
            return front->data;
        }
        // Handle the case where the queue is empty
        throw runtime_error("The queue is empty. No values to return");
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
