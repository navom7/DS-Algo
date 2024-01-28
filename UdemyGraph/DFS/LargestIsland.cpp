/*
Largest Island
You are given a m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

Constraints:

m == grid.length

n == grid[i].length

1 <= m, n <= 50

grid[i][j] is either 0 or 1.

Sample Input

grid = [
  [1, 0, 0, 1, 0],
  [1, 0, 1, 0, 0],
  [0, 0, 1, 0, 1],
  [1, 0, 1, 1, 1],
  [1, 0, 1, 1, 0]
]
Sample Output

8


*/


#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int m, int n) {
    visited[i][j] = true;
    int cs = 1;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    for(int k = 0; k < 4; k++) {
        int nx = i+dx[k];
        int ny = j+dy[k];

        if(nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == false && grid[nx][ny] == 1) {
            int subContinent = dfs(grid, visited, nx, ny, m, n);
            cs += subContinent;
        }
    }
    return cs;
}

int maxAreaOfIsland(vector<vector<int>> grid)
{
    // for(auto x: grid) {
    //     cout << "{";
    //     for(auto y: x) {
    //         cout << y << ", ";
    //     }
    //     cout << "}" << endl;
    // }

    int m = grid.size();
    int n = grid[0].size();

    int largestIsland = 0;

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j] && grid[i][j] == 1) {
                int cl = dfs(grid, visited, i, j, m, n);
                cout << i << " " << j << ": " << cl << endl;
                largestIsland = max(cl, largestIsland);
            }
        }
    }
    return largestIsland;
}


int main() {
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 },
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 },
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 }
    };

    cout << maxAreaOfIsland(grid) << endl;

}