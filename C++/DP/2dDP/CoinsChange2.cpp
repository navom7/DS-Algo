// Coin Change 2
// Given a value N and an integer vector COINS representing coins of different denominations. Considering you have infinite supply of each coin, your task is to find total number of combinations of these coins that make a sum of N.
// If that amount of money cannot be made up by any combination of the coins, return 0.
// Input Format:
// In the function an integer N is given, and a vector COINS consisting of coins.
// Output Format:
// Return an integer representing total number of combinations.
// Constraint:
// Total number of ways <= 10^12.
// Sample Testcase:
// Input:
// 4
// 1 2 3
// Output:
// 4
// Explanation:
// {1, 1, 1, 1}, {1, 1, 2}, {1, 3}, {2, 2} are different combinations having a sum of 4.

#include<iostream>
#include<vector>
using namespace std;

long long coinsDP(int n, int i, int amount, vector<int> &coins, vector<vector<long long>> &dp){
    if(amount == 0) {
        cout << i << " " << endl;
        return 1;
    }
    if(i == n || amount < 0) {
        return 0;
    }
    
    int inc1 = 0, inc2 = 0, exc = 0;
    if(amount >= coins[i]) {
        inc1 = coinsDP(n, i, amount-coins[i], coins, dp);
        inc2 = coinsDP(n, i+1, amount-coins[i], coins, dp);
    }
    exc = coinsDP(n, i+1, amount, coins, dp);
    
    // cout << i << " " << amount << " " << inc1 << " " << inc2 << " " << exc << endl;
    
    return inc1 + inc2 + exc;
}

long long coin_combinations(int N, const vector<int>& COINS) {
    vector<long long> dp(N + 1, 0);
    dp[0] = 1;

    for (int coin : COINS) {
        for (int i = coin; i <= N; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    for(auto x: dp) {
        cout << x << " ";
    }
    cout << endl;
    return dp[N];
}


long long findCombinations(int n, vector<int> coins){
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    for(auto coin: coins) {
        for(int i = coin; i <= n; i++) {
            dp[i] += dp[i-coin];
        }
    }
    return dp[n];
}

int main(){
    int n = 4;
    vector<int> coins = {1, 2, 3};
    // for(int i = 0; i < 3; i++) {
    //     cin >> coins[i];
    // }
    cout << findCombinations(n, coins) << endl;
    cout << coin_combinations(n, coins) << endl;


    return 0;
}