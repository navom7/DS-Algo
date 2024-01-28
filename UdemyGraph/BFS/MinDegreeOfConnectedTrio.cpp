// Minimum Degree of a Connected Trio in a Graph
// You are given an undirected graph. You are given an integer n which is the number of nodes in the graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.
// A connected trio is a set of three nodes where there is an edge between every pair of them.
// The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.
// Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.
// Constraints:
// 2 <= n <= 400
// edges[i].length == 2
// 1 <= edges.length <= n * (n-1) / 2
// 1 <= ui, vi <= n
// ui != vi
// There are no repeated edges.
// Example:
// Input: n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
// Output: 3
// Explanation: There is exactly one trio, which is [1,2,3]. The edges that form its degree are bolded in the figure above.

// Expected Time Complexity: O(n^3)

// #include<iostream>
// #include<vector>
// using namespace std;

int minTrioDegree(int n, vector<vector<int>> edges) {
    vector<vector<int>> matrix(n+1, vector<int>(n+1, 0));
    vector<int> rank(n + 1, 0);
    for(auto x: edges) {
        int i = x[0];
        int j = x[1];
                rank[i]++;
        rank[j]++;
                matrix[i][j] = 1;
        matrix[j][j] = 1;
    }

        int ans = INT_MAX;
        for(auto edge: edges) {
        int i = edge[0];
        int j = edge[1];
                for(int k = 1; k <= n; k++) {
            if(matrix[i][k] == 1 && matrix[j][k] == 1 && k != j) {
                cout << i << " " << j << " " << k << endl;
                ans = min(ans, rank[i] + rank[j] + rank[k] - 6);
            }
        }
    }
        return ans == INT_MAX ? -1 : ans;
}

int main() {
    int n = 6;
    vector<vector<int>> edges = {
        {1,2},{1,3},{3,2},{4,1},{5,2},{3,6}
    };
    cout << minTrioDegree(n, edges) << endl;
}