
/*

Travelling Salesman Using DP

*/


#include<iostream>
#include<vector>

using namespace std;

int travellingSalesmanDP(vector<vector<int>>& dist, int node, int visitedNodes, int n, vector<vector<int>>& dp) {
    if(visitedNodes == (1<<n) - 1) {
        return dist[node][0];
    }
    if(dp[visitedNodes][node] != -1) {
        return dp[visitedNodes][node];
    }

    int ans = INT_MAX;
    for(int choice = 0; choice < n; choice++) {
        if(((1<<choice) & visitedNodes) == 0) {
            visitedNodes = (visitedNodes | (1<<choice));
            int temp = dist[node][choice] + travellingSalesmanDP(dist, choice, visitedNodes, n, dp);
            ans = min(ans, temp);
        }
    }
    return dp[visitedNodes][node] = ans;
}


int main() {
    vector<vector<int>> dist = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
    };
    int n =  4;
    int visitedNodes = (1<<n)-1;
    vector<vector<int>> dp(visitedNodes, vector<int>(n, -1));

    int ans = travellingSalesmanDP(dist, 0, 1, n, dp);
    cout << ans << endl;

    return 0;
}