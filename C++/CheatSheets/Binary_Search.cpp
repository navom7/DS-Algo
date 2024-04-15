#include <iostream>
#include <vector>
#include <algorithm> // Required for STL functions

using namespace std;

int main() {
    vector<int> nums = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;

    // Binary Search using lower_bound and upper_bound functions
    // Time Complexity: O(log n)
    auto it_lower = lower_bound(nums.begin(), nums.end(), target); // First element not less than target
    auto it_upper = upper_bound(nums.begin(), nums.end(), target); // First element greater than target

    if (it_lower != nums.end() && *it_lower == target) {
        int index_lower = it_lower - nums.begin();
        cout << "Element " << target << " found at index (lower_bound): " << index_lower << endl;
    } else {
        cout << "Element " << target << " not found (lower_bound)" << endl;
    }

    if (it_upper != nums.end() && *it_upper == target) {
        int index_upper = it_upper - nums.begin() - 1;
        cout << "Element " << target << " found at index (upper_bound): " << index_upper << endl;
    } else {
        cout << "Element " << target << " not found (upper_bound)" << endl;
    }

    // Binary Search using binary_search function
    // Time Complexity: O(log n)
    bool exists = binary_search(nums.begin(), nums.end(), target); // Returns true if element exists
    cout << "Element " << target << " exists in array (binary_search): " << (exists ? "true" : "false") << endl;

    // Example of std::equal_range to get the range of equal elements
    // Time Complexity: O(log n)
    auto range = equal_range(nums.begin(), nums.end(), target);
    if (range.first != range.second) {
        int first_occurrence = range.first - nums.begin();
        int last_occurrence = range.second - nums.begin() - 1;
        cout << "First Occurrence of " << target << " at index: " << first_occurrence << endl;
        cout << "Last Occurrence of " << target << " at index: " << last_occurrence << endl;
    } else {
        cout << "Element " << target << " not found (equal_range)" << endl;
    }

    return 0;
}
