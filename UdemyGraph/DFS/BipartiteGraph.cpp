#include<iostream>
#include<vector>

using namespace std;

bool dfs_helper(vector<vector<int>> &graph, vector<int> &visited, int node, int parent, int color){
    visited[node] = color;

    for(auto nbr: graph[node]) {
        if(visited[node] == 0) {
            bool isBipartite = dfs_helper(graph, visited, nbr, node, 3-color);
            if(!isBipartite)
                return false;
        } else if(nbr != parent && visited[nbr] == color) {
            return false;
        }
    }
    return true;
}

bool dfs(vector<vector<int>> &graph, int N) {
    vector<int> visited(N, 0);
    return dfs_helper(graph, visited, 0, -1, 1);
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
    if(dfs(graph, N)) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}