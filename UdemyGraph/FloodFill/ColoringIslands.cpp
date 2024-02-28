/*

To find the largest island in a 1,0 matrix (often referred to as a binary matrix), 
where 1 represents land and 0 represents water, you can use the Depth-First Search (DFS) algorithm. 
The idea is to iterate over each cell in the matrix. When you encounter a cell with the value 1 (land), 
you start a DFS from that cell to count the size of the island it belongs to, 
marking visited land cells to avoid counting them more than once. After exploring the entire island, 
you compare its size to the current largest island found and update the maximum size accordingly. 
This process is repeated for all cells in the matrix to ensure all islands are considered.

Coloring of island

*/

#include<iostream>
#include<vector>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int R;
int C;


void floodFill(vector<vector<int>>& area, int x, int y, vector<vector<bool>>& visited, int colour) {
    area[x][y] = colour;
    visited[x][y] = true;
    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        if(nx >= 0 && nx < R && ny >= 0 && ny < C && visited[nx][ny] == false && area[nx][ny] == 1) {
            floodFill(area, nx, ny, visited, colour);
        }
    }
}


int main() {
    vector<vector<int>> area = {
        {0,0,0,1,1},
        {0,1,0,0,0},
        {1,1,0,1,0},
        {1,0,1,1,1},
        {0,0,1,1,0},
        {0,0,0,0,0}
    };
    R = area.size();
    C = area[0].size();

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    int count = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(area[i][j] == 1 && visited[i][j] == false) {
                count++;
                floodFill(area, i, j, visited, count);
            }
        }
    }
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << area[i][j] << " ";
        }
        cout << endl;
    }
    cout << count << endl;
}
