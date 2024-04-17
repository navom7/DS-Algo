#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int n) {
        V = n;
        l = new list<int>[V];
    }

    void addEdge(int a, int b, bool isUndir = true) {
        l[a].push_back(b);
        if(isUndir) {
            l[b].push_back(a);
        }
    }

    void sssp(int source, int dest) {
        queue<int> q;
        vector<bool> visited(V, false);
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);

        q.push(source);
        dist[source] = 0;
        visited[source] = true;
        // parent[source] = source;
        cout << "BFS: ";
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            cout << f << " ";
            for(auto nbr: l[f]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    dist[nbr] = dist[f]+1;
                    parent[nbr] = f;
                    q.push(nbr);
                }
            }
        }
        cout << endl;
        for(int i = 0; i < V; i++) {
            cout << "Distance of " << i << " is " << dist[i] << endl;
        }

        int temp = dest;
        while(temp != -1) {
            cout << temp << " -> ";
            temp = parent[temp];
        }

    }
};



int main() {
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0, 4);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);

    g.sssp(1, 6);

    return 0;
}