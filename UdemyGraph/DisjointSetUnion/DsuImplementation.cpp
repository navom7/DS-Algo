/*
Disjoint Set Union (DSU), also known as Union-Find, is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. It provides two primary operations:

Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
Union: Join two subsets into a single subset.
This data structure is very useful in network connectivity, where it can quickly determine whether two nodes are connected and connect disjoint graphs by merging nodes.
*/

#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph{
    int V;
    list<pair<int,int>> l;
public:
    Graph(int v) {
        V = v;
    }

    void addEdge(int u, int v) {
        l.push_back(make_pair(u,v));
    }

    int findSet(int i, int parent[]) {
        if(parent[i] == -1) {
            return i;
        }
        return findSet(parent[i], parent);
    }

    void union_set(int s1, int s2, int parent[]) {
        int p1 = findSet(s1, parent);
        int p2 = findSet(s2, parent);

        if(p1 != p2) {
            parent[p2] = p1;
        }
    }

    bool contains_cycle() {
        int *parent = new int[V];
        for(int i = 0; i < V; i++) {
            parent[i] = -1;
        }

        for(auto x: l) {
            int a = x.first;
            int b = x.second;

            int s1 = findSet(a, parent);
            int s2 = findSet(b, parent);

            if(s1 != s2) {
                union_set(s1, s2, parent);
            } else {
                return true;
            }
        }
        delete [] parent;
        return false;
    }


};


int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,0);

    cout << g.contains_cycle() << endl;

    return 0;
}