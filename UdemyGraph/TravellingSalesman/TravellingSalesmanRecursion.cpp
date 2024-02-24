/*

Travelling Salesman problem:

*/



#include<iostream>
#include<vector>

using namespace std;

int travellingSalesman(vector<vector<int>>& dist, int node, int visitedBits, int n) {
    if(visitedBits == ((1<<n)-1)) {
        return dist[node][0];
    }

    int ans = INT_MAX;
    for(int choice = 0; choice < n; choice++) {
        if((visitedBits & (1<<choice)) == 0) {

            cout << visitedBits <<"  " << choice << endl;
            int remainingDist = dist[node][choice] + travellingSalesman(dist, choice, visitedBits | (1 << choice), n);
            cout << remainingDist << " " << ans << endl;
            ans = min(ans, remainingDist);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> dist = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
    };
    int n = 4;
    int ans = travellingSalesman(dist, 0, 1, n);
    cout << "ans: " << ans << endl;
    return 0;
}