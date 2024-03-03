/*

6 6
0 1 0 0 1 0
0 1 1 1 1 0
0 0 0 0 1 0
0 0 1 1 1 1
1 1 1 1 1 1
1 0 0 0 0 1

3 4
0 0 0 1 
0 0 1 1
0 1 1 0

*/

#include<iostream>
#include<vector>
#include<climits>
#include<queue>


using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int R;
int C;

int minDist(vector<vector<int>>& arr) {
    queue<pair<int,int>> q;
    vector<vector<int>> dist(R, vector<int>(C, INT_MAX));

    for (int i = 0; i < C; i++)
    {
        if(arr[0][i] == 1) {
            q.push({0, i});
            dist[0][i] = 0;
        }
    }

    while(!q.empty()) {
        auto f = q.front();
        int i = f.first;
        int j = f.second;
        q.pop();

        if(i == R-1) {
            break;
        }

        for(int k = 0; k < 4; k++) {
            int nx = i+dx[k];
            int ny = j+dy[k];

            if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                
            } 
        }
    }
    
}



int main() {



}
