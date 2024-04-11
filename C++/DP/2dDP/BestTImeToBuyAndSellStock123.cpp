//LEETCODE: 123. Best Time to Buy and Sell Stock III
class Solution {
public:

    int maxProfitHelper(vector<int>& prices, int i, int flag, int sellCount, vector<vector<vector<int>>> &dp) {
        if(i == prices.size() || sellCount == 2)
            return 0;

        if(dp[i][flag][sellCount] != -1) {
            return dp[i][flag][sellCount];
        }

        int ans = 0;

        if(flag == 0) { //buy

            ans = max(ans, maxProfitHelper(prices, i+1, 1, sellCount, dp) - prices[i]);
            ans = max(ans, maxProfitHelper(prices, i+1, 0, sellCount, dp));

        } else { //sell

            ans = max(ans, maxProfitHelper(prices, i+1, 0, sellCount+1, dp) + prices[i]);
            ans = max(ans, maxProfitHelper(prices, i+1, 1, sellCount, dp));

        }

        return dp[i][flag][sellCount] = ans;

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, -1)));
        int ans = maxProfitHelper(prices, 0, 0, 0, dp);
        // for(auto x: dp) {
        //     for(auto y: x) {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};