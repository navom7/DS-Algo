#include<iostream>
#include<list>
#include<vector>

using namespace std;


class Node{
public:
    int n;
    list<int> nbrs;

    Node(int n) {
        n = n;
    }
};


bool compare(Node* a, Node* b) {
    return a->nbrs.size() > b->nbrs.size();
}


class Graph{
    vector<Node*> mp;
public:
    Graph(int v) {
        mp = vector<Node*>(v);
        for(int i = 0; i < v; i++) {
            mp[i] = new Node(i);
        }
    }

    void addEdge(int i, int j) {
        mp[i]->nbrs.push_back(j);
        mp[j]->nbrs.push_back(i);
    }

    void printAdjList() {
        for(auto x: mp) {
            cout << x->n << ": ";
            for(auto y: x->nbrs) {
                cout << y << ", ";
            }
            cout << endl;
        }
    }

    int findMaximalNetworks() {
        sort(mp.begin(), mp.end(), compare);
        return mp[0]->nbrs.size() + mp[1]->nbrs.size();
    }


};

int maximalNetworkRank(int n, vector<vector<int>> roads) {
    Graph g(n);
    for(auto x: roads) {
        g.addEdge(x[0], x[1]);
    }
    g.printAdjList();

    return g.findMaximalNetworks();
}

int main() {
    int n = 4;
    vector<vector<int>> roads = {
        {0,1}, {0,3}, {1,2}, {1,3}
    };
    cout << maximalNetworkRank(n, roads) << endl;
}