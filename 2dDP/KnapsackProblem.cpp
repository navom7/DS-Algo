#include<iostream>
#include<vector>

using namespace std;

//Recursive Code -> Top Down
int knapsack(int wts[], int prices[], int N, int W, vector<vector<int>> &dp) {
    if(N <= 0 || W <= 0) {
        return 0;
    }
    if(dp[N][W] != 0) {
        return dp[N][W];
    }
    int a = 0;
    if((W-wts[N-1]) > 0) {
        a = prices[N-1] + knapsack(wts, prices, N-1, W-wts[N-1], dp);
    }
    int b = knapsack(wts, prices, N-1, W, dp);

    return dp[N][W] = max(a, b);
}


int main() {

    int wts[] = {2, 7, 3, 4};
    int prices[] = {5, 20, 20, 10};
    int N = 4;
    int W = 11;

    vector<vector<int>> dp(N+1, vector<int>(W + 1, 0));
    cout << knapsack(wts, prices, N, W, dp) << endl;

    return 0;
}