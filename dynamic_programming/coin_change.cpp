// given an amount (i.e 15)
// and a list of coins i.e {1, 3, 7, 10}
// Find out minimum number of coins needed to make that amount

#include<bits/stdc++.h>
using namespace std;

int coin_change(vector<int> &coins, int amount, vector<int> &dp){
    if(amount <= 0){
        return 0;
    }
    
    if(dp[amount] != 0){
        // cout << dp[amount] << " " << amount << endl;
        return dp[amount];
    }
    int mn = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        if(amount >= coins[i])
            mn = min(mn, coin_change(coins, amount-coins[i], dp));
    }
    return dp[amount] = mn+1;
}

int count_change_bottom_up(vector<int> &coins, int amount, vector<int> &dp){
    if(amount == 0){
        return 0;
    }
    for(int i = 1; i <= amount; i++){
        for(int k = 0; k < coins.size(); k++){
            if(i >= coins[k]){
                dp[i] = min(dp[i], dp[i-coins[k]]+1);
            }
        }
    }
    return dp[amount];
}

int main(){
    int amount;
    cout << "Enter amount: ";
    cin >> amount;
    vector<int>dp(amount+1, 0);
    cout << endl << "Enter the number of types of coins: ";
    int n; cin >> n;
    vector<int> coins;
    while(n--){
        int temp;
        cout << endl << "enter next Number: ";
        cin >> temp;
        coins.push_back(temp);
    }
    cout << endl << "Minimum number of coins needed: " << coin_change(coins, amount, dp) << "\n\n\n\n\n";
    
    cout << endl << "count_change_bottom_up Minimum number of coins needed: " << count_change_bottom_up(coins, amount, dp) << "\n\n\n\n\n";
    return 0;
}