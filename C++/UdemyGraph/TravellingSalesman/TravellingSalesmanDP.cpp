
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
    cout << visitedNodes << " " << node << " " << endl;
    if(dp[visitedNodes][node] != -1) {
        return dp[visitedNodes][node];
    }
    cout << dp[visitedNodes][node] << endl;
    // cout << " here " << endl;

    int ans = INT_MAX;
    for(int choice = 0; choice < n; choice++) {
        // cout << "choices: " << choice << " ";
        if(((1<<choice) & visitedNodes) == 0) {
            
            //This i should not do as it will update the visitedNodes itself,
            // and hence there will be new visitedNodes for every choice
            // visitedNodes = (visitedNodes | (1<<choice));
            // cout << visitedNodes << " " << node << " " << choice << endl;
            
            int temp = dist[node][choice] + travellingSalesmanDP(dist, choice, ((1<<choice) | visitedNodes), n, dp);
            ans = min(ans, temp);
        }
    }
    dp[visitedNodes][node] = ans;
    return ans;
}


int main() {
    vector<vector<int>> dist = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
    };
    int n =  4;
    int visitedNodes = (1<<n);
    vector<vector<int>> dp(visitedNodes, vector<int>(n, -1));
    // cout << " here " << endl;
    int ans = travellingSalesmanDP(dist, 0, 1, n, dp);
    cout << "ans is: " << ans << endl;

    return 0;
}