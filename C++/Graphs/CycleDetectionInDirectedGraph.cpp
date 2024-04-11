#include<iostream>
#include<queue>
#include<vector>
#include<list>

using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j) {
        l[i].push_back(j);
    }

    bool dfs(int node, vector<bool> &visited, vector<bool> &inStack) {
        visited[node] = true;
        inStack[node] = true;

        for(auto nbr: l[node]) {
            if(inStack[nbr]) {
                return true;
            } else if(!visited[nbr]) {
                bool foundCycle = dfs(nbr, visited, inStack);
                if(foundCycle)
                    return true;
            }
            
        }

        inStack[node] = false;
        return false;
    }

    bool contains_cycle() {
        vector<bool> visited(V, false);
        vector<bool> inStack(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, visited, inStack))
                    return true;
            }
        }
    }

};

int main() {
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    // g.addEdge(2,0);

    cout << g.contains_cycle() << endl;


    return 0;
}