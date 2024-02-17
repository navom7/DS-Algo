/*
	Dijkstra's algorithm is a fundamental algorithm in computer science used for finding the shortest paths between nodes in a graph, which may represent, for example, road networks. It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later.

The algorithm exists in many variants; the original version found the shortest path between two nodes, but a more common variant fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a shortest-path tree.

Key Concepts
Graphs: Dijkstra's algorithm applies to both directed and undirected graphs. All edges must have non-negative weights. This is because, in each step of the algorithm, it picks the node with the smallest distance from the source; negative weights could lead to a situation where a longer path reduces the overall path cost, which Dijkstra's algorithm won't handle correctly.
Weighted Edges: Each edge of the graph has a weight (or cost), which represents the cost of moving from one vertex to another. This cost needs to be non-negative for Dijkstra's algorithm to work correctly.
Shortest Path Tree: For a given source vertex, the algorithm finds the shortest path to every other vertex, forming a tree-like structure of the shortest paths from the source to all other vertices.
*/


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
