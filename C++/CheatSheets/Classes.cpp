#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;


class Graph{
    int V;
    list<pair<int,int>> *p;
public:
    Graph(int v) {
        V = v;
        p = new list<pair<int,int>> [V];
    }

    void addEdge(int i, int j, int wt, bool isUndirected = true) {
        p[i].push_back(make_pair(wt, j));
        if(isUndirected) {
            p[j].push_back(make_pair(wt, i));
        }
    }

    void printGrapht() {
        for(int i = 0; i < V; i++) {
            cout << i << " --> ";
            for(auto x: p[i]) {
                cout << x.first << " and " << x.second << " ||";
            }
            cout << endl;
        }
    }

};


// Base class
class Animal {
public:
    // Constructor
    Animal(const string& name, int age) : name_(name), age_(age) {
        cout << "Animal constructor called\n";
    }

    // Destructor
    ~Animal() {
        cout << "Animal destructor called\n";
    }

    // Member function
    void printInfo() const {
        cout << "Name: " << name_ << ", Age: " << age_ << endl;
    }

protected:
    string name_;
    int age_;
};

// Derived class
class Dog : public Animal {
public:
    // Constructor using base class constructor
    Dog(const string& name, int age, const string& breed) : Animal(name, age), breed_(breed) {
        cout << "Dog constructor called\n";
    }

    // Destructor (automatically calls base class destructor)
    ~Dog() {
        cout << "Dog destructor called\n";
    }

    // Override base class function
    void printInfo() const {
        cout << "Name: " << name_ << ", Age: " << age_ << ", Breed: " << breed_ << endl;
    }

private:
    string breed_;
};

int main() {
    // Create an Animal object
    Animal animal("Leo", 5);
    animal.printInfo();

    cout << endl;

    // Create a Dog object
    Dog dog("Buddy", 3, "Golden Retriever");
    dog.printInfo();

    return 0;
}
