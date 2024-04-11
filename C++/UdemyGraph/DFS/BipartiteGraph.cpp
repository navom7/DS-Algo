/*
Is Graph Bipartite?
Given an undirected graph with n nodes, where each nodes is numbered 0 to  n-1.

You are given a 2D array, where for each v in graph[u] there is an undirected edge between node u and v.

If v is in graph[u], then u is in graph[v] (the graph is undirected).

The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

Return whether Graph is Bipartite or not.

Constraints:

1 <= n <= 100



Example :

Input:

graph = {{1,2,3},{0,2},{0,1,3},{0,2}}

Output:

false

Explanation:

There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.



Expected Time Complexity: O(n+m), where m represent number of edges.
*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs_helper(vector<vector<int>> &graph, vector<int> &visited, int node, int parent, int color){
    
    if(graph[node].size() == 0)
        return false;
    
    visited[node] = color;
    cout << node << " " << parent << " " << color << endl;
    for(auto nbr: graph[node]) {
        cout << "nbr is: " << nbr << endl;
        if(visited[nbr] == 0) {
            cout << "nbr when not visited: " << nbr << endl;
            bool isBipartite = dfs_helper(graph, visited, nbr, node, 3-color);
            if(!isBipartite) {
                return false;
            }
        } else if(nbr != parent && visited[nbr] == color) {
            cout << "nbr when already visited with color " << nbr << endl; 
            return false;
        }
    }
    return true;
}

bool dfs(vector<vector<int>> &graph, int N) {
    vector<int> visited(N, 0);
    bool ans = dfs_helper(graph, visited, 0, -1, 1);
    for(auto x: visited) {
        if(x == 0) {
            return false;
        }
    }
    return ans;
}


bool isBipartite(vector<vector<int>> graph){
    int N = graph.size();
    for(int i = 0; i < N; i++) {
        cout << i << " --> ";
        for(auto x: graph[i]) {
            cout << x << ", ";
        }
    }
    cout << endl;
    if(dfs(graph, N)) {
        return true;
    } else {
        return false;
    }
}

int main() {

    int N = 4;

    vector<vector<int>> graph = 
    {
        {0,1},
        {0,2},
        {0,3},
        {3,2},
        {1,2}
    };

    // while(M--) {
    //     int x, y;
    //     cin >> x >> y;
    //     graph[x].push_back(y);
    //     graph[y].push_back(x);
    // }
    if(isBipartite(graph)) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}