//Single source shortest path
// Need to find the shortest path from a souce to a destination



#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<queue>

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

    void sssp(int source, int dest) {
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


        int temp = dest;
        while(temp != -1) {
            cout << temp << " ";
            temp = parent[temp];
        }
        cout << endl;
    }

};


int main() {
    
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,5);
    g.addEdge(2,3);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);

    g.sssp(1,6);

    return 0;
}