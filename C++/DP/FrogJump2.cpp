/*
There are N stones, for each i (1 <= i <= N), the height of Stone i is h[i]. There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:
If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K. Here, a cost of |hi−hj| is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone N.
Input Format
Function contains a vector containing height of stones and an integer K.
Output Format
Return a single integer representing minimum possible total cost incurred.
Constraints
2 <= n <= 100000
1 <= k <= 100
1 <= h[i] <= 10000
Sample Testcase:
Input:
k= 3
10 30 40 50 20
Output:
30
*/


#include<bits/stdc++.h>
using namespace std;
long long minimumCost(vector<int> stones, int k){
    for(auto x: stones) {
        cout << x << " ";
    }
    cout << endl << k << endl;
    int n = stones.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k && j < n; j++) {
            dp[i] = min(dp[i], dp[i-j] + (abs(stones[i]-stones[i-j])));
        }
    }
    for(auto x: dp) {
        cout << x << " ";
    }
    return dp[n-1];
}