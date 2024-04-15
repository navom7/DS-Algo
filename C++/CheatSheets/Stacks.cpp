#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Creating a stack
    stack<int> s;

    // Push elements onto the stack
    s.push(10);  // O(1)
    s.push(20);  // O(1)
    s.push(30);  // O(1)

    // Check if stack is empty
    if (s.empty()) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack is not empty\n";
    }

    // Access the top element
    cout << "Top element: " << s.top() << "\n";  // O(1)

    // Get the size of the stack
    cout << "Size of stack: " << s.size() << "\n";  // O(1)

    // Pop elements from the stack
    while (!s.empty()) {
        cout << "Popping: " << s.top() << "\n";  // O(1)
        s.pop();  // O(1)
    }

    // After popping, stack should be empty
    if (s.empty()) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack is not empty\n";
    }

    return 0;
}
