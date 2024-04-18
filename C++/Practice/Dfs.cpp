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
        l[b].push_back(a);
    }

    bool dfsHelper(int source, vector<bool>& visited, int parent) {
        visited[source] = true;
        cout << source << ", ";

        for(auto x: l[source]) {
            if(!visited[x]) {
                bool isCycleFound = dfsHelper(x, visited, source);
                if(isCycleFound) {
                    return true;
                }
            } else {
                if(x != parent) {
                    return true;
                }
            }
        }
        return false;
    }


    void dfs(int source) {
        vector<bool> visited(V, false);
        bool res = dfsHelper(source, visited, -1);

        if(res) {
            cout << "\n cycle found\n";
        } else {
            cout << "\n cycle not found\n";
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

    g.dfs(1);



    return 0;
}