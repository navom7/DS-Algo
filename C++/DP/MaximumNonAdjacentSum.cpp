#include<iostream>
#include<vector>
#include<climits>

using namespace std;


//Top down DP solution
int maximumNonAdjacentSumTD(int i, int n, vector<int> &arr, vector<int> &dp) {
    if(i >= n) {
        return 0;
    }
    if(i == n-1) {
        return arr[i];
    }
    if(dp[i] != 0) {
        return dp[i];
    }
    int a = arr[i] + maximumNonAdjacentSumTD(i+2, n, arr, dp);
    int b = maximumNonAdjacentSumTD(i+1, n, arr, dp);
    
    return dp[i] = max(a,b);
}


//Bottom Up DP Solution
int maximumNonAdjacentSumBU(int n, vector<int> &arr) {
    vector<int> dp(n, 0);

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for(int i = 2; i < n; i++) {
        dp[i] = max(dp[i-2] + arr[i], dp[i-1]);
    }
    return dp[n-1];
}



int main() {
    int n;

    vector<int> arr = {6,10, 12, 7, 9, 14};
    n = arr.size();
    vector<int> dp(n, 0);
    cout << " Top Down: " << maximumNonAdjacentSumTD(0, n, arr, dp) << endl;

    cout << "Bottom Up: " << maximumNonAdjacentSumBU(n, arr) << endl;

    return 0;
}