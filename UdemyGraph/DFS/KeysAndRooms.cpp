#include<iostream.h>
#include<vector>
#include<list>
#include<unordered_set>
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

    void dfs(vector<bool> &visited, int source) {
        for(auto x: l[source]) {
            if(!visited[x]) {
                visited[x] = true;
                dfs(visited, x);
            }
        }
    }


};



bool canVisitAllRooms(vector<vector<int>> rooms) {
    int n = rooms.size();
    Graph g(n);
    
    for(int i = 0; i < n; i++) {
        for(int x: rooms[i]) {
            g.addEdge(i, x);
        }
    }

    vector<bool> visited(n, false);
    visited[0] = true;
    g.dfs(visited, 0);
    for(auto x: visited) {
        if(!x) {
            return false;
        }
    }
    return true;

}




int main() {


}