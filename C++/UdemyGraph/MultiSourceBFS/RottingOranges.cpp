/*

Rotting Oranges
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,

1 representing a fresh orange, or

2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Constraints:

m == grid.length

n == grid[i].length

1 <= m, n <= 10

grid[i][j] is 0, 1, or 2.

Example:



Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4


Expected Time Complexity: O(n*m)

*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int m;
int n;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};


int orangesRotting(vector<vector<int>>  arr)
{
    m = arr.size();
    n = arr[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
            if(arr[i][j] == 2) {
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
        cout << endl;
    }
    
    int ans = INT_MIN;
    
    while(!q.empty()) {
        cout << endl;
        pair<int,int> p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        cout << "i: " << i << ", j: " << j << endl;
        
        for(int k = 0; k < 4; k++) {
            int x = i+dx[k];
            int y = j+dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && arr[x][y] == 1 && dist[x][y] == INT_MAX) {
                cout << x << " " << y << " : was x and y \n";
                dist[x][y] = dist[i][j] + 1;
                if(dist[x][y] > ans) {
                    ans = dist[x][y];
                }
                q.push({x,y});
            }
        }
        
    }
    cout << "dist array: " << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 1 && dist[i][j] == INT_MAX) {
                return -1;
            }
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return ans == INT_MIN ? 0 : ans;
}

