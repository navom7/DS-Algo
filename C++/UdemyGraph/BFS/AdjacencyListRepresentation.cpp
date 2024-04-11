#include<iostream>
#include<list>

using namespace std;

class Graph{
    int V;

    //list is declared as *l because initially size of list is not known
    list<int> *l;
public:
    Graph(int v) {
        this->V = v;

        //dynamic size initialisation to the list as it was defined as *l
        l = new list<int>[V]; //V number of list
    }

    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        if(undir) {
            l[j].push_back(i);
        }
    }

    void printAdjList() {
        for(int i = 0; i < V; i++) {
            cout << i << "--->";
            for(auto x: l[i]) {
                cout << x << ", ";
            }
            cout << endl;
        }
    }

};


int main() {
    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);

    g.printAdjList();
    

    return 0;
}