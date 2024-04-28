#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declaration and initialization
    vector<int> vec = {1, 2, 3, 4, 5};

    // Accessing elements
    cout << "Element at index 2: " << vec[2] << endl;        // O(1)
    cout << "Element at index 3: " << vec.at(3) << endl;     // O(1)
    cout << "First element: " << vec.front() << endl;        // O(1)
    cout << "Last element: " << vec.back() << endl;          // O(1)

    // Iterating over elements
    cout << "Elements: ";
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;

    // Modifying vector
    vec.push_back(6);                                        // O(1) amortized
    vec.pop_back();                                          // O(1)
    vec.insert(vec.begin() + 2, 8);                          // O(n) where n is number of elements to shift
    vec.erase(vec.begin() + 3);                              // O(n) where n is number of elements to shift
    vec.clear();                                             // O(n) linear in the size of the vector

    // Capacity-related operations
    cout << "Size: " << vec.size() << endl;                  // O(1)
    cout << "Capacity: " << vec.capacity() << endl;          // O(1)
    cout << "Is empty?: " << (vec.empty() ? "Yes" : "No") << endl; // O(1)
    
    // Resizing
    vec.resize(10);                                          // O(n) if resizing to a larger size

    // Other operations
    vector<int> vec2 = {10, 20, 30};

    //this swaps the entire element i.e v1 size = 4 and v2 size = 8, after swap
    //v1 size becomes 8 and v2 size becomes 4
    vec.swap(vec2);                                          // O(1) constant time swap of internal data



    vector<int> numbers = {10, 20, 30, 40, 50, 30, 20, 10};

    int target = 30; // Element to search for

    // Find the first occurrence of 'target' in the vector
    auto firstOccurrence = find(numbers.begin(), numbers.end(), target);

    // Find the last occurrence of 'target' in the vector
    auto lastOccurrence = find_end(numbers.begin(), numbers.end(), 
                                    &target, &target + 1);

    if (firstOccurrence != numbers.end()) {
        cout << "First occurrence of " << target << " at index: " 
             << distance(numbers.begin(), firstOccurrence) << endl;
    } else {
        cout << "Element " << target << " not found in the vector." << endl;
    }

    if (lastOccurrence != numbers.end()) {
        cout << "Last occurrence of " << target << " at index: " 
             << distance(numbers.begin(), lastOccurrence) << endl;
    } else {
        cout << "Element " << target << " not found in the vector." << endl;
    }



    return 0;
}
