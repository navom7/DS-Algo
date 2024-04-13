
Include Header:
```
#include <set>


```

Namespace:
```
using namespace std;


```

Initialization:
```
// Empty set of integers
set<int> mySet;

// Set initialized with elements
set<int> mySet = {3, 1, 4, 1, 5, 9};

// Copy constructor
set<int> anotherSet(mySet.begin(), mySet.end());


```

Insertion:
```
mySet.insert(42); // Insert 42 into the set


```

Deletion:
```
mySet.erase(5); // Remove the element 5 from the set


```

Iterating Over Elements:
```
for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    cout << *it << " ";
}
cout << endl;


```

Checking if Element Exists:
```
if (mySet.find(42) != mySet.end()) {
    cout << "Element 42 is in the set" << endl;
}


```

Size of Set:
```
cout << "Size of set " << mySet.size() << endl;

```

Clearing the Set:
```
mySet.clear(); // Remove all elements from the set


```

Checking if Set is Empty:
```
if (mySet.empty()) {
    cout << "Set is empty" << endl;
}


```

Iterators:
```
auto it = mySet.begin(); // Iterator to the beginning of the set
auto endIt = mySet.end(); // Iterator just past the end of the set

// Using iterators to print all elements
for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    cout << *it << " ";
}
cout << endl;


```

Finding and Counting Elements:
```
auto foundIt = mySet.find(5); // Find element 5
if (foundIt != mySet.end()) {
    cout << "Element 5 found in the set" << endl;
}

int countOf5 = mySet.count(5); // Count occurrences of element 5

cout << "Count of 5 in the set " << countOf5 << endl;

```

Lower and Upper Bounds:
```
auto lower = mySet.lower_bound(3); // Iterator to the first element not less than 3
auto upper = mySet.upper_bound(7); // Iterator to the first element greater than 7

// Iterate over elements in range [lower, upper)
for (auto it = lower; it != upper; ++it) {
    cout << *it << " ";
}
cout << endl;




```

Range-based For Loop:
```
for (const auto& elem : mySet) {  cout << elem << " ";
}
cout << endl;


```

Custom Comparator:
```
// Custom comparator for case-insensitive comparison of strings
struct CaseInsensitiveCompare {
    bool operator()(const string& a, const string& b) const {
        return strcasecmp(a.c_str(), b.c_str()) < 0;
    }
};

// Set of strings with case-insensitive comparison
set<string, CaseInsensitiveCompare> caseInsensitiveSet;

```



This cheat sheet covers the essential operations and usage patterns for set in C Remember to exercise caution when using using namespace std; in real-world projects to avoid potential naming conflicts and unintended behavior.





