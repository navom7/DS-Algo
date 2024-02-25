#include<iostream>
#include<vector>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int R;
int C;

void floodFill(vector<vector<int>>& area, int x, int y) {
    area[x][y] = 0;
    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        if(nx >= 0 && nx < R && ny >= 0 && ny < C && area[nx][ny] == 1) {
            floodFill(area, nx, ny);
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
    int count = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(area[i][j] == 1) {
                count++;
                floodFill(area, i, j);
            }
        }
    }

    cout << count << endl;
}