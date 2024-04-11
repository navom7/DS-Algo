/*

Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Constraints:

m == grid.length

n == grid[i].length

1 <= m, n <= 300

grid[i][j] is '0' or '1'.



Example:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


Expected Time Complexity: O(n*m)

*/


#include<iostream>
#include<vector>
using namespace std;

int R;
int C;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

void floodFill(vector<vector<char>>& area, int x, int y) {
    area[x][y] = '0';
    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        if(nx >= 0 && nx < R && ny >= 0 && ny < C && area[nx][ny] == '1') {
            floodFill(area, nx, ny);
        }
    }
}


int numIslands( vector<vector<char>> grid)
{
    R = grid.size();
    C = grid[0].size();
    
    int count = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i][j] == '1') {
                count++;
                floodFill(grid, i, j);
            }
        }
    }
    return count;
}

int main() {


    return 0;
}