//LEETCODE: 309
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfitHelper(vector<int>& prices, int type, int i, int n, vector<vector<int>> &dp) {
        // cout << type << " " << i << " " << bought << endl;
        if(i == n) {
            // cout << "returning\n";
            return 0;
        }
        if(dp[i][type] != -1) {
            return dp[i][type];
        }
        int ans = INT_MIN;
        if(type == 0) {//buy
            ans = max(ans, maxProfitHelper(prices, 1, i+1, n, dp) - prices[i]);
            ans = max(ans, maxProfitHelper(prices, 0, i+1, n, dp));
        } else if(type == 1) {
            ans = max(ans, prices[i] + maxProfitHelper(prices, 2, i+1, n, dp));
            ans = max(ans, maxProfitHelper(prices, 1, i+1, n, dp));
        } else {
            return dp[i][type] = maxProfitHelper(prices, 0, i+1, n, dp);
        }
        // cout<< endl << a << " " << b << endl << endl;
        return dp[i][type] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (3,-1));
        int ans = maxProfitHelper(prices, 0, 0, n, dp);
        
        for(auto x: dp) {
            for(auto y: x) {
                cout << y << " ";
            }
            cout << endl;
        }
        return ans;
    }
};


int main() {
    vector<int> prices = {2,1,4};


    return 0;
}