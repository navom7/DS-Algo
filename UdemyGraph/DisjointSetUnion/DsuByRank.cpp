/*
In the Disjoint Set data structure, each set is represented by a tree, with one element serving as the root. When a union operation is performed to merge two sets, the root of one set becomes the child of the root of the other set. Without any optimization, this could lead to a skewed tree where the path from some elements to the root of the tree becomes very long, which in turn makes find operations slow.

To avoid this issue, Union by Rank keeps track of the "rank" of each tree, which is an upper bound on its height. When two sets are united, the root of the tree with a lower rank becomes a child of the root with the higher rank. If both trees have the same rank, one is chosen as the new root arbitrarily, and its rank is incremented by one, as this is the only case where the height of the tree can increase.
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

    void addEdge(int a, int b) {
        l.push_back({a,b});
    }

    int findSet(int i, int parent[]) {
        if(parent[i] == -1){
            return i;
        }
        return findSet(parent[i], parent);
    }

    void unionSet(int a, int b, int parent[], int rank[]) {
        int s1 = findSet(a, parent);
        int s2 = findSet(b, parent);

        cout << a << " " << s1 << " " << b << " " << s2 << endl;
        if(s1 != s2) {
            if(rank[s1] > rank[s2]) {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            } else {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
        }
        cout << "here" << endl;
    }

    bool contains_cycle() {
        int *parent = new int[V];
        int *rank = new int[V];

        for(int i = 0; i < V; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }

        for(auto edge: l) {
            int a = edge.first;
            int b = edge.second;
            cout << a << " " << b << " : a and b:" << endl;
            int s1 = findSet(a, parent);
            cout << s1 << ": s1" << endl;
            int s2 = findSet(b, parent);
            cout << s2 << ": s2" << endl;
            // cout << s1 << " " << s2 << endl;
            if(s1 != s2) {
                unionSet(s1, s2, parent, rank);
            } else {
                return true;
            }
        }
        delete [] parent;
        delete [] rank;

        return false;
    }

};

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout << g.contains_cycle() << endl;

    return 0;
}