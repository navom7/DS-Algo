/*

Shortest Bridge
In a given 2D binary array grid, there are two islands. (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped. (It is guaranteed that the answer is at least 1.)

Constraints:

2 <= grid.length == grid[0].length <= 100

grid[i][j] == 0 or grid[i][j] == 1



Example:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2


Expected Time Complexity: O(n*m), where n and m are the number of rows and columns in the grid respectively

*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int m;
int n;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};


void coloring(vector<vector<int>>& arr, int i, int j) {
    
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    q.push({i,j});
    visited[i][j] = true;
    
    while(!q.empty()) {
        
        pair<int,int> p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        
        arr[i][j] = 2;
        
        // cout << "i: " << i << ", j: " << j << endl;
        
        for(int k = 0; k < 4; k++) {
            int x = i+dx[k];
            int y = j+dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && arr[x][y] == 1 && visited[x][y] == false) {
                // cout << x << " " << y << " : was x and y \n";
                visited[x][y] = true;
                q.push({x,y});
            }
        }
        
    }
}

void color(vector<vector<int>>& arr) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 1) {
                coloring(arr, i, j);
                return;
            }
        }
    }
}




int shortestBridge(vector<vector<int>> arr)
{
    
    m = arr.size();
    n = arr[0].size();
    
    color(arr);
    
    queue<vector<int>> q;
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int x = arr[i][j];
            if(x == 1 or x == 2) {
                q.push({i, j, x});
                dist[i][j] = 0;
            }
        }
    }
    int ans = INT_MAX;
    
    while(!q.empty()) {
        
        auto p = q.front();
        q.pop();
        int i = p[0];
        int j = p[1];
        int color = p[2];
        
        cout << i << " " << j << " " << color << endl;
        
        for(int k = 0; k < 4; k++) {
            int x = i+dx[k];
            int y = j+dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n) {
                if(arr[x][y] == 0) {
                    arr[x][y] = color;
                    q.push({x, y, color});
                    dist[x][y] = dist[i][j] + 1;
                } else if(arr[x][y] != color) {
                    ans = min(ans, dist[i][j] + dist[x][y]);
                } else {
                    continue;
                }
            }
        }
        
    }
    
    
    return ans;
}