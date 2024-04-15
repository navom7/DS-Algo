#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Declaration and initialization of a queue
    queue<int> q;

    // Insert elements into the queue
    q.push(10); // O(1)
    q.push(20); // O(1)
    q.push(30); // O(1)

    // Access the front and back elements of the queue
    cout << "Front element: " << q.front() << endl; // O(1)
    cout << "Back element: " << q.back() << endl;   // O(1)

    // Check if the queue is empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // O(1)

    // Get the size of the queue
    cout << "Size of queue: " << q.size() << endl; // O(1)

    // Remove the front element from the queue
    q.pop(); // O(1)

    // Access the new front element after popping
    cout << "Front element after pop: " << q.front() << endl; // O(1)

    // Iterating over the queue
    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " "; // O(1)
        q.pop();                  // O(1)
    }
    cout << endl;

    return 0;
}
