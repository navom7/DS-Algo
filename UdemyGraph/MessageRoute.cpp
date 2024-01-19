/*
Message Route
There is a network of n computers, each computer is numbered 1 to n.

The computer network is given as an array of edges where edges[i] = [ui, vi] is a bidirectional edge that connects computer ui and computer vi .

Your task is to find if Alice can send a message to Bob, if it is possible, return minimum number of computers on such a route and if it is not possible than return -1.

Alice's Computer is 1 and Bob's computer is  n.

Constraints:

2≤ n ≤10^5

1<= edges.length <= 2*10^5

1<= ui, vi <=n



Expected Time Complexity:  O (n + edges.length)
*/





#include<bits/stdc++.h>
using namespace std;


class Graph{
    int V;
    list<int> *l;

public:
    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        if(undir) {
            l[j].push_back(i);
        }
    }

    int sssp(int source, int dest) {
        queue<int> q;
        vector<bool> visited(V, false);
        vector<int> parent(V+1, -1);
        vector<int> dist(V+1, INT_MAX);

        q.push(source);
        visited[source] = true;
        dist[source] = 0;
        

        while(!q.empty()) {
            int frnt = q.front();
            q.pop();

            for(auto x: l[frnt]) {
                if(!visited[x]){
                    parent[x] = frnt;
                    dist[x] = dist[frnt]+1;
                    q.push(x);
                    visited[x] = true;
                }
            }

        }

        return dist[dest] + 1;
    }

};


int messageRoute(int n, vector<vector<int>>edges)
{
    Graph g(n+1);
    for(auto x: edges) {
        int i = x[0];
        int j = x[1];
        g.addEdge(i, j);
    }
    
    return g.sssp(1, n);
}