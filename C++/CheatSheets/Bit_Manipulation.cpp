#include <iostream>

using namespace std;

int main() {
    // Initialize an integer for bit manipulation
    int number = 8;  // Binary: 101010

    // Print the binary representation of the number
    cout << "Binary representation of " << number << ": ";
    for (int i = sizeof(number) * 8 - 1; i >= 0; --i) {
        cout << ((number >> i) & 1);
    }
    cout << endl;
    
    // Set a bit at a specific position (zero-based indexing)
    int bitPositionToSet = 3;
    number |= (1 << bitPositionToSet);  // Set bit at position 3 (from right)
    // Time complexity: O(1)

    // Clear a bit at a specific position
    int bitPositionToClear = 5;
    number &= ~(1 << bitPositionToClear);  // Clear bit at position 5 (from right)
    // Time complexity: O(1)

    // Toggle a bit at a specific position
    int bitPositionToToggle = 2;
    number ^= (1 << bitPositionToToggle);  // Toggle bit at position 2 (from right)
    // Time complexity: O(1)

    // Check if a bit is set at a specific position
    int bitPositionToCheck = 3;
    bool isBitSet = (number & (1 << bitPositionToCheck)) != 0;
    // Time complexity: O(1)

    // Count the number of set bits (population count)
    int numberOfSetBits = __builtin_popcount(number);  // Requires GCC or Clang
    // Time complexity: O(log n)

    // Find the position of the least significant set bit (1-based indexing)
    int leastSignificantSetBitPosition = __builtin_ffs(number);  // Requires GCC or Clang
    // Time complexity: O(log n)

    // Find the position of the most significant set bit (1-based indexing)
    int mostSignificantSetBitPosition = 0;
    if (number != 0) {
        mostSignificantSetBitPosition = sizeof(number) * 8 - __builtin_clz(number);  // Requires GCC or Clang
    }
    // Time complexity: O(log n)

    // Print the updated binary representation of the number
    cout << "Binary representation after operations: ";
    for (int i = sizeof(number) * 8 - 1; i >= 0; --i) {
        cout << ((number >> i) & 1);
    }
    cout << endl;

    // Output results
    cout << "Is bit at position " << bitPositionToCheck << " set? " << (isBitSet ? "Yes" : "No") << endl;
    cout << "Number of set bits: " << numberOfSetBits << endl;
    cout << "Position of least significant set bit: " << leastSignificantSetBitPosition << endl;
    cout << "Position of most significant set bit: " << mostSignificantSetBitPosition << endl;

    return 0;
}
