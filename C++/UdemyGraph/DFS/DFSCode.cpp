#include<iostream>
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

    void addEdge(int a, int b, bool undir = true) {
        l[a].push_back(b);
        if(undir) {
            l[b].push_back(a);
        }
    }

    void dfsHelper(vector<bool> &visited, int source) {
        cout << source << " ";
        for(auto x: l[source]) {
            if(!visited[x]) {
                visited[x] = true;
                dfsHelper(visited, x);
            }
        }
    }

    void dfs(int source) {
        vector<bool> visited(V, false);
        visited[source] = true;
        dfsHelper(visited, source);
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
	g.dfs(1);

    return 0;
}