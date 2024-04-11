// FROG JUMPS
// ============
// Given an array containing integers, and there is a frog 
// sitting at the starting of the array. Each integer represents the 
// maximum number of steps frog can take in the array.
// Write a function which can calculates the minimum jumps 
// required by frog to reach the end of the array.
/*
6
30 10 60 10 60 50
*/

#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int getMinCostBU(vector<int> &stones, int n) {
    vector<int> dp(n, 0);
    dp[1] = abs(stones[1]-stones[0]);

    for(int i = 2; i < n; i++) {
        dp[i] = min(dp[i-1] + abs(stones[i] - stones[i-1]), dp[i-2] + abs(stones[i] - stones[i-2]));
    }
    return dp[n-1];
}

int getMinCostTD(vector<int> &stones, int n, int i, vector<int> &dp) {
    // cout << "n: " << n << endl;
    if(i >= n-1) {
        // cout << "I: " << i << endl;
        return 0;
    }
    if(dp[i] != 0) {
        // cout << "I: " << i << " dp[i]: " << dp[i] << endl;
        return dp[i];
    }
    int a = INT_MAX, b = INT_MAX;
    if(i+1 < n) {
        a = abs(stones[i+1] - stones[i]) + getMinCostTD(stones, n, i+1, dp);
    }
    if(i+2 < n) {
        b = abs(stones[i+2] - stones[i]) + getMinCostTD(stones, n, i+2, dp);
    }
    cout << endl << "---------->" << a << " " << b << " " << i << " " << endl;
    return dp[i] = min(a, b);
}



int main() {
    int n; cin >> n;
    vector<int> stones(n);

    for(int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    cout << "Bottom Up: " << getMinCostBU(stones, n) << endl;

    vector<int> dp(n, 0);
    // for(auto x: dp) {
    //     cout << x << " ";
    // }
    // cout << endl << endl;
    cout << "Top Down: " << getMinCostTD(stones, n, 0, dp) << endl;

    return 0;


}