#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int coinChange(int sum, vector<int> &coins) {
    vector<int> dp(sum+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= sum; i++) {
        for(auto coin: coins) {
            if((i-coin) >= 0 && dp[i-coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
    }
    return dp[sum] == INT_MAX ? -1 : dp[sum];
}

int coinChangeTD(int sum, vector<int> &coins, vector<int> &dp, int i) {
    if(sum == 0) {
        return dp[sum] = 0;
    }
    if(dp[sum] != INT_MAX) {
        return dp[sum];
    }

    if(i >= coins.size()) {
        return dp[sum] = INT_MAX;
    }

    for(int i = 0; i < coins.size(); i++) {
        if(sum-coins[i] >= 0){
            int a = coinChangeTD(sum - coins[i], coins, dp, i+1);
            dp[sum] = min(dp[sum], a+1);
        }
    }
    // cout << sum << " " << coins[i] << " " << a << " " << b << endl;
    return dp[sum];
}

int main() {
    vector<int> coins = {1,5,7,10};
    int sum; cin >> sum;
    cout << "coind change: " << coinChange(sum, coins) << endl;

    vector<int> dp(sum+1, INT_MAX);
    int i = 0;
    cout << "coind change top down: " << coinChangeTD(sum, coins, dp, i) << endl;


    return 0;
}