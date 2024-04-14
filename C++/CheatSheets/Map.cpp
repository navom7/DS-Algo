#include <iostream>
#include <map>

using namespace std;


// Function to search for a value in a map
template<typename K, typename V>
bool searchByValue(const map<K, V>& myMap, const V& value) {
    for (auto& pair : myMap) {
        if (pair.second == value) {
            return true; // Value found
        }
    }
    return false; // Value not found
}

// Function to delete elements by value from a map
template<typename K, typename V>
void deleteByValue(map<K, V>& myMap, const V& value) {
    auto it = myMap.begin();
    while (it != myMap.end()) {
        if (it->second == value) {
            it = myMap.erase(it); // Erase element and move iterator to next
        } else {
            ++it; // Move to next element
        }
    }
}



int main() {
    // Declaration
    map<int, string> myMap;

    // Insertion (avg O(log n))
    myMap.insert({1, "apple"});
    myMap.emplace(2, "banana");

    // Accessing elements (avg O(log n))
    cout << "myMap[1]: " << myMap[1] << endl; // prints "apple"

    // Checking existence (avg O(log n))
    if (myMap.find(2) != myMap.end()) {
        cout << "Key 2 exists in myMap" << endl;
    }

    // Size (O(1))
    cout << "Size of myMap: " << myMap.size() << endl;

    // Iteration through all elements (O(n))
    cout << "All elements in myMap:" << endl;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    // Deletion by key (avg O(log n))
    myMap.erase(1);

    // Clearing the map (O(n))
    myMap.clear();

    return 0;
}
