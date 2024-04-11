#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *nbrs;
public:
    Graph(int v) {
        V = v;
        nbrs = new list<int>[V];
    }
    
    void addEdge(int i, int j) {
        nbrs[i].push_back(j);
        nbrs[j].push_back(i);
    }
    
    bool isCyclic(int source) {
        cout << "source: " << source << endl;
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *parent = new int[V];
        for(int i = 0; i < V; i++) {
            parent[i] = -1;
        }
        
        q.push(source);
        visited[source] = true;
        
        while(!q.empty()) {
            int frnt = q.front();
            q.pop();
            
            for(auto nbr: nbrs[frnt]) {
                cout << "nbr: " << nbr << " frnt: " << frnt << endl;
                if(nbr == parent[frnt])
                    continue;
                if(visited[nbr] && parent[frnt] != nbr) {
                    cout << "nbr: " << nbr << endl;
                    return true;
                }
                visited[nbr] = true;
                parent[nbr] = frnt;
                q.push(nbr);
            }
        }
        return false;
    }

    bool dfs(int node, vector<bool> &visited, int parent) {
        visited[node] = true;

        for(auto nbr: nbrs[node]) {
            if(!visited[nbr]) {
                bool nbrFoundACycle = dfs(nbr, visited, node);
                if(nbrFoundACycle)
                    return true;
            } else if(parent != nbr) {
                return true;
            }
        }
        return false;
    }

    bool contains_cycle_dfs() {
        vector<bool> visited(V, false);
        return dfs(0, visited, -1);
    }
    
};

bool contains_cycle(int V,vector<pair<int,int> > edges){
    Graph g(V);
    for(auto x: edges) {
        cout << x.first << " " << x.second << endl;
        g.addEdge(x.first, x.second);
    }
    return g.isCyclic(edges[0].first);
    
    
}



int main() {
    Graph g(3);

    g.addEdge(0,1);
    g.addEdge(1,2);
    // g.addEdge(2,0);

    cout << g.contains_cycle_dfs() << endl;

    return 0;
}