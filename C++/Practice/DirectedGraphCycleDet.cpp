#include<iostream>
#include<vector>
#include<list>

using namespace std;


class Graph{
    int V;
    list<int> *l;
public:
    Graph(int n) {
        V = n;
        l = new list<int>[V];
    }
    
    void addEdge(int a, int b) {
        l[a].push_back(b);
    }

    bool dfsHelper(int source, vector<bool>& visited, vector<bool>& instack, int parent) {
        visited[source] = true;
        instack[source] = true;

        for(auto x: l[source]) {
            if(!visited[x]) {
                bool found = dfsHelper(x, visited, instack, parent);
                if(found)
                    return true;
            } else {
                if(x != parent && instack[x] == true) {
                    return true;
                }
            }
        }
        instack[source] = false;
    }

    bool detectCycle() {
        vector<bool> visited(V, false);
        vector<bool> instack(V, false);
        for(int i = 0; i < V; i++) {
            if(dfsHelper(i, visited, instack, -1)) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,0);
    g.addEdge(0,4);
    g.addEdge(5,4);
    g.addEdge(0,5);

    if(g.detectCycle()) {
        cout << "cycle found\n";
    } else {
        cout << "\nnot found\n";
    }



    return 0;
}


