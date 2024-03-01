/*

6 6
0 0 0 0 0 0
0 1 1 0 1 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 1 0 0 0
1 0 0 0 0 1

3 4
0 0 0 1 
0 0 1 1
0 1 1 0

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;


int main() {
    int m, n;
    cin >> m >> n;
    int arr[m][n], dist[m][n];
    pair<int,int> nearest[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            dist[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 1) {
                for(int ni = 0; ni < m; ni++) {
                    for(int nj = 0; nj < n; nj++) {
                        if(dist[ni][nj] > (abs(ni-i) + abs(nj-j))) {
                            dist[ni][nj] = (abs(ni-i) + abs(nj-j));
                            nearest[ni][nj] = {i, j};
                        }
                    }
                }
            }
        }
    }
    cout << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << nearest[i][j].first << "," << nearest[i][j].second << " ";
        }
        cout << endl;
    }


    return 0;
}