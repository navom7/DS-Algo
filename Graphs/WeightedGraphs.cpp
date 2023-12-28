#include<iostream>
#include<list>

using namespace std;

class Graph{
    int V;
    list<pair<int,int>> *p;
public:
    Graph(int v) {
        V = v;
        p = new list<pair<int,int>> [V];
    }

    void addEdge(int i, int j, int wt, bool isUndirected = true) {
        p[i].push_back(make_pair(wt, j));
        if(isUndirected) {
            p[j].push_back(make_pair(wt, i));
        }
    }

    void printGrapht() {
        for(int i = 0; i < V; i++) {
            cout << i << " --> ";
            for(auto x: p[i]) {
                cout << x.first << " and " << x.second << " ||";
            }
            cout << endl;
        }
    }

};

int main() {
    Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,2);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

    g.printGrapht();

    return 0;
}