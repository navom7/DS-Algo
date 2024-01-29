/*
Directed Graph Cycle Detection
Given a directed graph having n nodes, and an array of edges where edges[i] = [ui, vi] is an edge directed from node ui to node vi .

Find whether the graph contains a cycle or not, return true if the cycle is present else return false.

Constraints:

1<= n <= 10^5

1<= edges.length <= 10^5

1<= ui, vi <= n

Nodes are numbered 1 to n

Graph may or may not be connected

Input :n =  5, edges = {{1,  2}, {1, 3}, {2, 3}, {1,  4}, {4, 5}}
Output : false
*/


#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v) {
        this->V = v;
        this->l = new list<int>[V];
    }

    void addEdge(int a, int b) {
        l[a].push_back(b);
    }

    bool dfs(int source, vector<bool> &visited, vector<bool> &instack) {
        visited[source] = true;
        for(auto x: l[source]) {
            if(!visited[x]) {
                instack[x] = true;
                bool backedgeFound = dfs(x, visited, instack);
                if(backedgeFound)
                    return true;
            } else if(instack[x]) {
                return true;
            }
        }
        instack[source] = false;
        return false;
    }

};


bool solve(int n, vector<vector<int>>edges) {
    Graph g(n+1);
    cout << n << " " << endl;
    for(auto x: edges) {
        cout << x[0] << " : " << x[1] << endl;
        g.addEdge(x[0], x[1]);
    }

    for(int i = 1; i <= n; i++) {
        vector<bool> visited(n+1, false);
        vector<bool> instack(n+1, false);
        bool foundCycle = g.dfs(i, visited, instack);
        if(foundCycle) {
            cout << " found! " << endl;
            return true;
        }
    }
    cout << "not found!" << endl;
    return false;

}


int main() {


    return 0;
}