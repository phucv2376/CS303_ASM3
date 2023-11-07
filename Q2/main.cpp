#include "queue.h"

using namespace std;

int main()
{
    Queue<int> intQueue;

    intQueue.enqueue(11);
    intQueue.enqueue(22);
    intQueue.enqueue(33);

    cout << "Front of Queue: " << intQueue.getFront() << endl;
    cout << "Queue size: " << intQueue.getSize() << endl;

    cout << "The following value was dequeued: " << intQueue.dequeue() << endl;
    cout << "The following value was dequeued: " << intQueue.dequeue() << endl;

    cout << "Queue is currently empty: " << (intQueue.isEmpty() ? "true" : "false") << endl;
    return 0;
}
