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


bool compare(pair<int, Node*> a, pair<int, Node*> b) {
    return a.second->nbrs.size() > b.second->nbrs.size();
}

bool isOverlap(list<int> a, list<int> b) {
    for(auto x: a) {
        for(auto y: b) {
            if(x == y)
                return true;
        }
    }
    return false;
}


class Graph{
    vector<pair<int,Node*>> mp;
public:
    Graph(int v) {
        mp = vector<pair<int, Node*>>(v);
        for(int i = 0; i < v; i++) {
            mp[i] = {i, new Node(i)};
        }
    }

    void addEdge(int i, int j) {
        mp[i].second->nbrs.push_back(j);
        mp[j].second->nbrs.push_back(i);
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

    int findMaximalNetworks() {
        sort(mp.begin(), mp.end(), compare);
        int overlap = 0;
        if(isOverlap(mp[0].second->nbrs, mp[1].second->nbrs))
            overlap = 1;
        return mp[0].second->nbrs.size() + mp[1].second->nbrs.size() - 1;
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