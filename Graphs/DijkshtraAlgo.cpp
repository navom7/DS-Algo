#include<iostream>
#include<climits>
#include<set>
#include<list>

using namespace std;

class Graph{
    int V;
    list<pair<int,int>> *l;
public:
    Graph(int v) {
        V = v;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int i, int j, int wt, bool undir = true) {
        l[i].push_back({wt, j});
        if(undir) {
            l[j].push_back({wt, i});
        }
    }

    int dijkshtra(int source, int dest) {
        set<pair<int,int>> s;
        vector<int> dist(V, INT_MAX);

        s.insert({0, source});
        dist[source] = 0;

        while(!s.empty()) {
            auto it = s.begin();
            int distTillNow = it->first;
            int node = it->second;
            s.erase(it); // similar to pop

            for(auto nbrPair: l[node]) {
                int currentEdge = nbrPair.first;
                int nbr = nbrPair.second;

                if((distTillNow + currentEdge) < dist[nbr]) {
                    auto f = s.find({dist[nbr], nbr});
                    if(f != s.end()) {
                        s.erase(f);
                    }

                    dist[nbr] = distTillNow + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }

        for(int i = 0; i < V; i++) {
            cout << "Node: " << i << " Dist: " << dist[i] << endl;
        }
        return dist[dest];
    }


};

int main() {
    Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout << g.dijkshtra(0,4) << endl;

    return 0;
}