#include<iostream>
#include<vector>
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

    void addEdge(int a, int b) {
        l[a].push_back(b);
    }

    void topological_sort() {
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto x: l[i]) {
                indegree[x]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int frnt = q.front();
            q.pop();
            cout << frnt << " ";

            for(auto x: l[frnt]) {
                indegree[x]--;
                if(indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
    }

};

int main() {

    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(1,4);
    g.addEdge(1,2);

    g.topological_sort();

}