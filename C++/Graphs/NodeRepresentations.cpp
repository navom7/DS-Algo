#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Node{
public:
    string name;
    vector<string> nbrs;
    Node(string name) {
        this->name = name;
    }

};

class Graph{
    unordered_map<string, Node*> mp;
public:
    Graph(vector<string> cities) {
        for(auto city: cities) {
            mp[city] = new Node(city);
        }
    }

    void addEdge(string a, string b, bool isUndirected = false) {
        mp[a]->nbrs.push_back(b);
        if(isUndirected) {
            mp[b]->nbrs.push_back(a);
        }
    }

    void printAdj() {
        for(auto x: mp) {
            cout << x.first << "--> ";
            for(auto y: x.second->nbrs) {
                cout << y << ", ";
            }
            cout << endl;
        }
    }

};

int main() {
    vector<string> cities = {"Delhi","London","Paris","New York"};
	Graph g(cities);

	g.addEdge("Delhi","London");
	g.addEdge("New York","London");
	g.addEdge("Delhi","Paris");
	g.addEdge("Paris","New York");

    g.printAdj();

    return 0;
}