/*
Cycle Detection in Undirected Graph
Given a undirected graph having n nodes, and an array of edges where edges[i] = [ui, vi] is a bidirectional edge between node ui and node vi .

Find whether the graph contains a cycle or not, return true if the cycle is present else return false.

Constraints:

3<= n <= 10^5

2<= edges.length <= 10^5

1<= ui, vi <= n

Nodes are numbered 1 to n

Graph may or may not be connected

Input : n = 5 , edges = {{1,  2}, {1, 3}, {2, 3}, {1,  4}, {4, 5}}
Output : true
*/


#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    
public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }
    
    void addEdge(int a, int b, bool undir = true) {
        l[a].push_back(b);
        if(undir) {
            l[b].push_back(a);
        }
    }
    
    bool dfs(vector<bool> &visited, int source, int parent) {
        visited[source] = true;
        for(auto x: l[source]) {
            if(!visited[x]) {
                int foundCycle = dfs(visited, x, source);
                if(foundCycle)
                    return true;
            } else if(parent != x) {
                return true;
            }
        }
        return false;
    }
    
};

bool solve(int n, vector<vector<int> > edges) {
    cout << n << ": " << endl;
    
    Graph g(n+1);
    for(auto x: edges) {
        cout << x[0] << " : " << x[1] << endl;
        g.addEdge(x[0], x[1]);
    }
    for(int i = 1; i <= n; i++) {
        
        vector<bool> visited(n+1, false);
        bool cycleFound = g.dfs(visited, i, -1);
        if(cycleFound)
            return true;
    }
    return false;
    
}