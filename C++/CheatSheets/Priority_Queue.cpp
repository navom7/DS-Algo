#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Define a custom class representing a Person
class Person {
private:
    string name;
    int age;

public:
    Person(const string& name, int age) : name(name), age(age) {}

    const string& getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};

// Define a custom functor for comparing Person objects by age (ascending order)
struct CompareByAge {
    bool operator()(const Person& p1, const Person& p2) const {
        return p1.getAge() > p2.getAge(); // Min-heap based on age (ascending order)
    }
};




int main() {
    // Creating a max-heap using std::priority_queue
    priority_queue<int> maxHeap;

    // Insert elements into the max-heap
    maxHeap.push(5);
    maxHeap.push(10);
    maxHeap.push(3);
    maxHeap.push(8);

    cout << "Current max-heap size: " << maxHeap.size() << endl; // Output: 4

    // Print all elements in the max-heap (note: priority_queue doesn't provide direct access to elements)
    cout << "Current max-heap elements: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " "; // Output: 10 8 5 3 (elements are sorted in descending order)
        maxHeap.pop();
    }
    cout << endl;

    // Creating a min-heap using std::priority_queue with custom comparator
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements into the min-heap
    minHeap.push(5);
    minHeap.push(10);
    minHeap.push(3);
    minHeap.push(8);

    cout << "Current min-heap size: " << minHeap.size() << endl; // Output: 4

    // Print all elements in the min-heap (note: priority_queue doesn't provide direct access to elements)
    cout << "Current min-heap elements: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " "; // Output: 3 5 8 10 (elements are sorted in ascending order)
        minHeap.pop();
    }
    cout << endl;






    // Create a priority_queue of Person objects using custom comparison
    priority_queue<Person, vector<Person>, CompareByAge> minAgeHeap;

    // Insert Person objects into the min-heap
    minAgeHeap.push(Person("Alice", 25));
    minAgeHeap.push(Person("Bob", 30));
    minAgeHeap.push(Person("Charlie", 20));

    // Print all Person objects in the min-heap (sorted by age in ascending order)
    cout << "Persons sorted by age (ascending order):" << endl;
    while (!minAgeHeap.empty()) {
        const Person& person = minAgeHeap.top();
        cout << person.getName() << " - Age: " << person.getAge() << endl;
        minAgeHeap.pop();
    }

    return 0;
}
