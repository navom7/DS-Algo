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

    void addEdge(int i, int j, bool isUndirected = true){
        l[i].push_back(j);
        if(isUndirected) {
            l[j].push_back(i);
        }
    }

    void dfsHelper(int source, bool *visited) {
        visited[source] = true;
        cout << source << " ";
        for(auto x: l[source]) {
            if(!visited[x]) {
                dfsHelper(x, visited);
            }
        }
    }

    void dfs(int source) {
        bool *visited = new bool[V]{0};
        dfsHelper(source, visited);
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