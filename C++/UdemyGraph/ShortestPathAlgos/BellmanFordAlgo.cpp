/*
The Bellman-Ford algorithm is a graph search algorithm that computes the shortest paths from a single source vertex to all other vertices in a weighted digraph (directed graph). Unlike Dijkstra's algorithm, which only works with graphs that have no negative weight edges, the Bellman-Ford algorithm can handle graphs with negative weight edges and can detect negative weight cycles in the graph.

How Bellman-Ford Algorithm Works:
Initialization: Initialize the distance to the source vertex to 0 and all other vertices to infinity. Set the predecessor for each vertex to null.

Relaxation: For each edge (u, v) in the graph, if the distance to the destination vertex v can be shortened by taking the edge (u, v), update the distance to v to the sum of the distance to u and the weight of the edge (u, v). This step is repeated for all edges, and it is done V - 1 times, where V is the number of vertices in the graph.

Check for Negative Weight Cycles: After V - 1 iterations, perform one more iteration over all edges to check for any decrease in distances. If a distance is decreased, then there is a negative weight cycle in the graph.

Key Points:
The algorithm's time complexity is 
�
(
�
�
)
O(VE), where 
�
V is the number of vertices and 
�
E is the number of edges in the graph.
The presence of a negative weight cycle makes it impossible to define the shortest path (since the cycle could be traversed repeatedly to reduce the path length indefinitely), and the algorithm can report its existence.

*/



#include<iostream>
#include<vector>
#include<climits>

using namespace std;


vector<int> bellmanFord(int V, int source, vector<vector<int>> &edges) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;


    //Relaxation of all the edges V-1 times
    for(int i = 0; i < V-1; i++) {
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    //after relaxation, if any edge availabe whose distance is greater that distance of its upcoming neigbor
    //then it has negative weight cycle
    for(auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(dist[v] > dist[u] + wt) {
            cout << "Contains negative weight cycle\n";
            exit(0);
        }
    }

    return dist;
}


int main()  {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back({u,v,wt});
    }

    vector<int> distances = bellmanFord(n+1, 1, edges);
    for(auto x: distances) {
        cout << x << " ";
    }
    cout << endl;
}