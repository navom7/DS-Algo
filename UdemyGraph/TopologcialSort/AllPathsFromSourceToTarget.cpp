/*
All Paths From Source to Target
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Constraints:

n == graph.length

2 <= n <= 15

0 <= graph[i][j] < n

graph[i][j] != i (i.e., there will be no self-loops).

The input graph is guaranteed to be a DAG.

Sample Input :

[ [1,2],

  [3],

  [3],

  [] ]

Sample Output :

[ [0,1,3],

  [0,2,3] ]


*/


#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node, vector<vector<int>> &res, vector<int> vec, int n) {
    visited[node] = true;
    vec.push_back(node);
    cout << node << " ";
    if(node == n-1) {
        res.push_back(vec);
    }
    for(auto nbr: graph[node]) {
        if(!visited[nbr]) {
            dfs(graph, visited, nbr, res, vec, n);
        }
    }
    visited[node] = false;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<vector<int>> res;
    vector<int> vec;
    dfs(graph, visited, 0, res, vec, n);
    return res;
}

