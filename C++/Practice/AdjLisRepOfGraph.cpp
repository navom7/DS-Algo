#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>

using namespace std;

class Node{
public:
    string name;
    list<string> nbrs;

    Node(string n) {
        this->name = n;
    }

};


class Graph{
    unordered_map<string, Node*> mp;

public:
    Graph(vector<string> vec) {
        for(auto x: vec) {
            mp[x] = new Node(x);
        }
    }

    void addEdge(string a, string b, bool isUndir = true) {
        mp[a]->nbrs.push_back(b);
        if(isUndir) {
            mp[b]->nbrs.push_back(a);
        }
    }


    void printAdjList() {
        for(auto x: mp) {
            cout << x.first << ": ";
            for(auto y: x.second->nbrs) {
                cout << y << ", ";
            }
            cout << endl;
        }

    }

};


int main() {
    vector<string> vec = {"london", "delhi", "new york", "paris"};
    Graph g(vec);

    g.addEdge("new york", "london", false);
    g.addEdge("delhi", "london", false);
    g.addEdge("delhi", "paris", false);
    g.addEdge("paris", "new york", false);

    g.printAdjList();



    return 0;
}