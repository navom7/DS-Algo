/*
Detecting an Odd Length Cycle
Given an undirected graph as an adjacency list, return whether the graph has an odd length cycle.

Constraints:

n, m ≤ 250 where n and m are the number of rows and columns in graph

Input

graph = [
    [1, 2, 3],
    [0, 2],
    [0, 1, 3],
    [0, 2]
]
Output

true
Explanation

One odd length cycle would be 0 -> 2 -> 1 -> 0



Expected  Time Complexity: O(n+m)
*/




#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &dist, int node, int parent) {
    if(visited[node])
        return false;
    visited[node] = true;
    dist[node] = dist[parent] + 1;
    
    for(auto nbr: graph[node]) {
        if(!visited[nbr]) {
            bool isOddCycle = dfs(graph, visited, dist, nbr, node);
            if(isOddCycle)
                return true;
        } else if(nbr != parent && dist[nbr]%2 != 0) {
            return true;
        }
    }
    return false;
}

bool solve(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> dist(n, 1);
    for(int i = 0; i < n; i++) {
        bool isOddCyclePresent = dfs(graph, visited, dist, i, -1);
        if(isOddCyclePresent)
            return true;
    }
    return false;
}