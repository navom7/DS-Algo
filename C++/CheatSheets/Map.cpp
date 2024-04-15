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








//----------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------



    // Declaration and initialization of a map
    myMap = {
        {1, "apple"},
        {2, "banana"},
        {3, "orange"},
        {4, "pear"}
    };

    // Accessing elements using operator[]
    cout << "myMap[2]: " << myMap[2] << endl; // Output: "banana"

    // Insertion using insert or emplace
    myMap.insert({5, "grape"});
    myMap.emplace(6, "melon");

    // Size of the map
    cout << "Size of myMap: " << myMap.size() << endl;

    // Iterating through all elements using iterators
    cout << "All elements in myMap:" << endl;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    // Checking existence of a key
    if (myMap.find(3) != myMap.end()) {
        cout << "Key 3 exists in myMap" << endl;
    }

    // Counting occurrences of a key
    cout << "Count of key 4 in myMap: " << myMap.count(4) << endl;

    // Deleting elements by key
    myMap.erase(5);

    // Deleting elements by range (C++17)
    auto it = myMap.find(3);
    if (it != myMap.end()) {
        myMap.erase(it); // Erase element at iterator position
    }

    // Checking if map is empty
    cout << "Is myMap empty? " << (myMap.empty() ? "Yes" : "No") << endl;

    // Finding elements by value
    string searchValue = "orange";
    auto valueIt = find_if(myMap.begin(), myMap.end(),
                           [&searchValue](const pair<int, string>& p) {
                               return p.second == searchValue;
                           });
    if (valueIt != myMap.end()) {
        cout << "Key with value '" << searchValue << "' found: "
             << valueIt->first << endl;
    } else {
        cout << "Value '" << searchValue << "' not found in myMap" << endl;
    }

    // Clearing the map
    myMap.clear();

    // Using stream insertion to print map elements (C++17)
    map<int, string> anotherMap = {
        {10, "one"},
        {20, "two"},
        {30, "three"}
    };
    // cout << "Another map elements: ";
    // copy(anotherMap.begin(), anotherMap.end(),
    //      ostream_iterator<pair<const int, string>>(cout, ", "));
    // cout << endl;


    return 0;
}
