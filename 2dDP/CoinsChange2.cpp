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

#include<bits/stdc++.h>

using namespace std;

long long coinsDP(int n, int i, vector<int> &coins, vector<vector<long long>> &dp){
    if(n == 0) {
        return 1;
    }
    if(i <= 0) {
        return 0;
    }
    if(dp[n][i] != 0) {
        return dp[n][i];
    }
    long long inc = 0, exc = 0;
    if(n >= coins[i-1]) {
        inc = coinsDP(n-coins[i-1], i-1, coins, dp);
    }
    exc = coinsDP(n, i-1, coins, dp);
    return dp[n][i] = inc+exc;
    
}
long long findCombinations(int n, vector<int> coins){
    vector<vector<long long>> dp(n, vector<long long> (coins.size(), 0));
    return coinsDP(n, coins.size(), coins, dp);
}