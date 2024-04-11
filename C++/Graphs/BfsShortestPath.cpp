#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph{
   int V;
   list<int> * l;
public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undirected = true) {
        l[i].push_back(j);
        if(undirected) {
            l[j].push_back(i);
        }
    }

    void bfs(int source, int dest) {
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *dist = new int[V]{0};
        int *parent = new int[V];

        q.push(source);
        parent[source] = -1;
        visited[source] = true;

        while(!q.empty()) {
            int frnt = q.front();
            q.pop();
            cout << frnt << " " << dist[frnt] << " || ";

            for(auto x: l[frnt]) {
                if(!visited[x]) {
                    q.push(x);
                    visited[x] = true;
                    dist[x] = dist[frnt] + 1;
                    parent[x] = frnt;
                }
            }
        }
        cout << endl << endl;

        //Shortest distance to every node
        for(int i = 0; i < V; i++) {
            cout << "distance from source to " << i << " is " << dist[i] << endl;
        }
        cout << endl;
        if(dest != -1) {
            int temp = dest;
            while(temp != source) {
                cout << temp << " -- ";
                temp = parent[temp];
            }
            cout << source;
        }
    }

};


int main() {
    Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.bfs(1,6);


    return 0;
}