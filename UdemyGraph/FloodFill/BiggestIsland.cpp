/*

Coloring of island

*/

#include<iostream>
#include<vector>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int R;
int C;
int colourCount[100] = {0};


void floodFill(vector<vector<int>>& area, int x, int y, vector<vector<bool>>& visited, int colour) {
    area[x][y] = colour;
    colourCount[colour]++;
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

    for(int i = 0; i <= count; i++) {
        cout << i << " " << colourCount[i] << endl;
    }

    cout << count << endl;
}