#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>


using namespace std;


class Node{
public:
    string cityName;
    list<string> nbrs;

    Node(string city) {
        this->cityName = city;
    }


};

class Graph{

    //map of all the nodes present in the string with
    //city name as key, and Node* as the Node of that list from that city node
    unordered_map<string, Node*> mp;

public:
    Graph(vector<string> cities) {
        for(auto city: cities) {
            mp[city] = new Node(city);
        }
    }

    void addEdge(string a, string b, bool undir = false) {
        mp[a]->nbrs.push_back(b);
        if(undir) {
            mp[b]->nbrs.push_back(a);
        }
    }

    void printAdjList() {
        for(auto cityNode: mp) {
            cout << cityNode.first << " --> ";
            for(auto x: cityNode.second->nbrs) {
                cout << x << ", ";
            }
            cout << endl;
        }
    }

    


};


int main() {
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);
    g.addEdge("Delhi","London");
	g.addEdge("New York","London");
	g.addEdge("Delhi","Paris");
	g.addEdge("Paris","New York");

	g.printAdjList();


    return 0;
}

