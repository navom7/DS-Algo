#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // Declaration
    unordered_map<string, int> umap;

    // Insertion (Time Complexity: Average O(1), Worst Case O(n))
    umap["apple"] = 3;
    umap["banana"] = 5;
    umap["orange"] = 2;

    // Size (Time Complexity: O(1))
    cout << "Size of unordered_map: " << umap.size() << endl;

    // Accessing elements
    // 1. Using [] operator (Time Complexity: Average O(1), Worst Case O(n))
    cout << "Number of apples: " << umap["apple"] << endl;

    // 2. Using at() method (Time Complexity: Average O(1), Worst Case O(n))
    cout << "Number of oranges: " << umap.at("orange") << endl;

    // Check if key exists (Time Complexity: Average O(1), Worst Case O(n))
    if (umap.find("banana") != umap.end()) {
        cout << "Banana found!" << endl;
    }

    // Iterating through unordered_map
    // Time Complexity: O(n), where n is the number of elements
    for (auto it = umap.begin(); it != umap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

    // Erase by key (Time Complexity: Average O(1), Worst Case O(n))
    umap.erase("orange");

    // Clearing the unordered_map (Time Complexity: Linear to the number of elements)
    umap.clear();

    return 0;
}
