/*
Detect Cycles in Grid
Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value as the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.

Constraints:

m == grid.length

n == grid[i].length

1 <= m <= 500

1 <= n <= 500

grid consists only of lowercase English letters.



Expected Time Complexity: O(n*m)
*/



#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited, int pi, int pj, int m, int n) {
    visited[i][j] = true;
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    for(int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == grid[i][j]) {
            if(!visited[nx][ny]) {
                bool foundCycle = dfs(grid, nx, ny, visited, i, j, m, n);
                if(foundCycle)
                    return true;
            } else if(nx != pi && ny != pj) {
                return true;
            }
        }
    }
    return false;
}

bool containsCycle(vector<vector<char>> grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    bool found = dfs(grid, 0, 0, visited, -1, -1, m, n);
    cout << found << endl;
    return found;
}