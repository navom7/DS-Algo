/*
Minimum Spanning Cost
Given a weighted undirected graph. Find the sum of weights of edges of a Minimum Spanning Tree.

The graph is given as an array of edges where edges[i] = [u, v, w] is a bidirectional edge between node u and node v with weight w. Each node has labels in the set {1,2,.......,n}.

Constraints:

1<= n <= 10^4

1<= edges.length <= 10^5

1<= u, v  <= n

1<= w <= 1000

Input : n = 4, edges  = {{1,  2,  7}, {1,  4,  6}, {4 ,2,  9}, {4,  3,  8}, {2,  3, 6}}
Output  : 19
*/

#include<iostream>
#include<list>
#include<vector>
using namespace std;

class DSU{
    int *rank;
    int* parent;
public:
    DSU(int n) {
        rank = new int[n];
        parent = new int[n];
        
        for(int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = -1;
        }
    }
    int findSet(int i) {
        if(parent[i] == -1) {
            return i;
        }
        return parent[i] = findSet(parent[i]);
    }
    
    void unite(int a, int b) {
        int s1 = findSet(a);
        int s2 = findSet(b);
        
        if(s1 != s2) {
            if(rank[s1] > rank[s2]) {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            } else {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
        }
    }
};

class Graph{
    int V;
    vector<vector<int>> edgeList;
    
public:
    Graph(int n) {
        V = n;
    }
    
    void addEdge(int a, int b, int w) {
        edgeList.push_back({w, a, b});
    }
    
    int krushkal_mst() {
        
        DSU d(V);
        int ans = 0;
        
        sort(edgeList.begin(), edgeList.end());
        
        for(auto edge: edgeList) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            
            int s1 = d.findSet(x);
            int s2 = d.findSet(y);
            
            if(s1 != s2) {
                d.unite(s1, s2);
                ans += w;
            }
        }
        
        return ans;
    }
    

    
    
};

int MST(int n, vector<vector<int>> edges)
{
     Graph g(n+1);
     for(auto x: edges) {
         g.addEdge(x[0], x[1], x[2]);
     }
     return g.krushkal_mst();
}

int main() {


    return 0;
}