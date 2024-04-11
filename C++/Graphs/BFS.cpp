#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool isUndirected = true) {
        l[i].push_back(j);
        if(isUndirected) {
            l[j].push_back(i);
        }
    }

    void bfs(int source) {
        queue<int> q;
        bool *visited = new bool[V]{0};

        q.push(source);
        visited[source] = true;

        while(!q.empty()) {
            int frnt = q.front();
            cout << frnt << " ";
            q.pop();

            for(auto x: l[frnt]) {
                if(!visited[x]) {
                    q.push(x);
                    visited[x] = true;
                }
            }
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
	g.bfs(1);


    return 0;
}