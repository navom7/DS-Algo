/*

Number of Closed Islands
Given a 2D grid consists of 0s (land) and 1s (water). An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Constraints:

1 <= grid.length, grid[0].length <= 100

0 <= grid[i][j] <=1



Example:

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).


Expected Time Complexity: O(n), where n is the total number of cells. We flood-fill all land cells once.

*/

#include<iostream>
#include<vector>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int R;
int C;


bool floodFill(vector<vector<int>>& area, int x, int y, vector<vector<bool>>& visited, bool &isIsland) {
    visited[x][y] = true;
    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
            if(area[nx][ny] == 0 && visited[nx][ny] == false) {
                floodFill(area, nx, ny, visited, isIsland);
            }
        } else {
            isIsland = false;
        }
    }
    return true;
}


int closedIsland(vector<vector<int>> area) {
    
    R = area.size();
    C = area[0].size();
    for(auto x: area) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    int count = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(area[i][j] == 0 && visited[i][j] == false) {
                bool isIsland = true;
                floodFill(area, i, j, visited, isIsland);
                if(isIsland) {
                    cout << i << " " << j << endl;
                    count++;
                }
            }
        }
    }
    return count;
}