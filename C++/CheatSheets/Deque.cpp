#include <iostream>
#include <deque>

using namespace std;

int main() {
    // Creating a deque
    deque<int> dq;

    // Pushing elements to the back of the deque - O(1)
    dq.push_back(10);  // dq: [10]
    dq.push_back(20);  // dq: [10, 20]
    dq.push_back(30);  // dq: [10, 20, 30]

    // Pushing elements to the front of the deque - O(1)
    dq.push_front(5);  // dq: [5, 10, 20, 30]

    // Accessing elements at specific positions - O(1)
    cout << "Element at index 2: " << dq[2] << endl;  // Output: Element at index 2: 20

    // Getting the front and back elements - O(1)
    cout << "Front element: " << dq.front() << endl;  // Output: Front element: 5
    cout << "Back element: " << dq.back() << endl;    // Output: Back element: 30

    // Checking if the deque is empty - O(1)
    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl;  // Output: Is deque empty? No

    // Getting the size of the deque - O(1)
    cout << "Deque size: " << dq.size() << endl;  // Output: Deque size: 4

    // Popping elements from the front and back of the deque - O(1)
    dq.pop_front();  // dq: [10, 20, 30]
    dq.pop_back();   // dq: [10, 20]

    // Iterating over the deque
    cout << "Deque elements: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;  // Output: Deque elements: 10 20

    return 0;
}
