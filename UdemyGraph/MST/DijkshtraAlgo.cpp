/*

Dijkstra's algorithm is a fundamental algorithm in graph theory used to find the shortest paths from a single source vertex to all other vertices in a graph with non-negative edge weights. It's widely used in various applications such as network routing protocols.

How Dijkstra's Algorithm Works:
Initialization: Set the distance to the source vertex to zero and to all other vertices to infinity. Set the predecessor of each vertex to null, indicating the start of the path.

Priority Queue: Maintain a priority queue (min-heap) that stores vertices by their current shortest distance from the source. Initially, it contains all vertices with their distances (source vertex distance is 0, and infinity for all others).

Relaxation: Extract the vertex with the minimum distance from the priority queue in each step. For this extracted vertex, consider all its adjacent vertices and calculate their tentative distances through the extracted vertex. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one. For every vertex visited, update its distance and predecessor if a shorter path is found.

Repeat Step 3: Continue this process until the priority queue is empty.

Result: After the priority queue is empty, the algorithm finishes. The distance value for each vertex reflects the shortest distance from the source vertex, and the predecessor relationship represents the shortest path.

Key Points:
The algorithm only works correctly when all edge weights are non-negative because, in each step, it greedily selects the vertex with the minimum distance.
The complexity of Dijkstra's algorithm depends on the data structure used for the priority queue. Using a binary heap, the time complexity is 
�
(
(
�
+
�
)
log
⁡
�
)
O((V+E)logV), where 
�
V is the number of vertices and 
�
E is the number of edges in the graph.

*/



#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std;


class Graph{

	int V;
	list<pair<int,int> > *l;

public:
	Graph(int v){
		V = v;
		l = new list<pair<int,int> >[V];
	}

	void addEdge(int u,int v,int wt,bool undir = true){

		l[u].push_back({wt,v});
		if(undir){
			l[v].push_back({wt,u});
		}
	}

    int dijkshtra(int source, int dest) {
        vector<int> dist(V, INT_MAX);
        set<pair<int,int>> s;

        dist[source] = 0;
        s.insert({0, source});

        while(!s.empty()) {
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;

            s.erase(it);

            for(auto nbrPair: l[node]) {
                int nbr = nbrPair.second;
                int newDist = nbrPair.first;



                if(dist[nbr] > newDist + distTillNow) {

                    auto idx = s.find({dist[nbr], nbr});
                    if(idx != s.end()) {
                        s.erase(idx);
                    }
                    dist[nbr] = newDist + distTillNow;
                    s.insert({dist[nbr], nbr});
                }
            }
        }

        return dist[dest];

    }


};


int main(){

	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout << g.dijkshtra(0,4)<<endl;

    return 0;
}