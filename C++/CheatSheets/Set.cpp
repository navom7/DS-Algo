#include <set>
#include <iostream>
using namespace std;

int main() {
    // Initialization
    set<int> mySet; // O(1)
    set<int> anotherSet = {3, 1, 4, 1, 5, 9}; // O(n * log(n)), n is the number of elements

    // Insertion
    mySet.insert(42); // O(log(n))

    // Deletion
    mySet.erase(5); // O(log(n))

    // Iterating Over Elements
    for (auto it = mySet.begin(); it != mySet.end(); ++it) { // O(n)
        cout << *it << " ";
    }
    cout << endl;

    // Checking if Element Exists
    if (mySet.find(42) != mySet.end()) { // O(log(n))
        cout << "Element 42 is in the set" << endl;
    }

    // Size of Set
    cout << "Size of set: " << mySet.size() << endl; // O(1)

    // Clearing the Set
    mySet.clear(); // O(n)

    // Checking if Set is Empty
    if (mySet.empty()) { // O(1)
        cout << "Set is empty" << endl;
    }

    // Finding and Counting Elements
    auto foundIt = mySet.find(5); // O(log(n))
    if (foundIt != mySet.end()) {
        cout << "Element 5 found in the set" << endl;
    }

    int countOf5 = mySet.count(5); // O(log(n) + k), k is the number of elements equal to 5
    cout << "Count of 5 in the set: " << countOf5 << endl;

    // Lower and Upper Bounds
    auto lower = mySet.lower_bound(3); // O(log(n))
    auto upper = mySet.upper_bound(7); // O(log(n))

    // Iterate over elements in range [lower, upper)
    for (auto it = lower; it != upper; ++it) { // O(log(n) + m), m is the number of elements in the range
        cout << *it << " ";
    }
    cout << endl;

    // Range-based For Loop
    for (const auto& elem : mySet) { // O(n)
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
