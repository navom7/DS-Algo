#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // Declaration and Initialization
    unordered_set<int> mySet = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // Insertion - O(1) average, O(n) worst-case
    mySet.insert(8);
    mySet.insert(7);

    // Size - O(1)
    cout << "Size of set: " << mySet.size() << endl;

    // Iteration - O(n)
    cout << "Set elements:";
    for (const auto& elem : mySet) {
        cout << " " << elem;
    }
    cout << endl;

    // Accessing elements - Not supported directly due to unordered nature

    // Find operation - O(1) average, O(n) worst-case
    auto it = mySet.find(5);
    if (it != mySet.end()) {
        cout << "Found element 5 in set" << endl;
    } else {
        cout << "Element 5 not found in set" << endl;
    }

    // Erase operation - O(1) average, O(n) worst-case
    mySet.erase(2);

    // Check if empty - O(1)
    cout << "Is set empty? " << (mySet.empty() ? "Yes" : "No") << endl;

    // Clearing the set - O(n)
    mySet.clear();

    return 0;
}
