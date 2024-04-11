#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int rodCuttingRecursive(int size, vector<int> &price, vector<int> &dp) {
    if(size == 0)
        return 0;
    if(size < 0) {
        return INT_MIN;
    }
    if(dp[size] > 0) {
        return dp[size];
    }
    int ans = INT_MIN;
    for(int i = 1; i <= size; i++) {
        int remainingCost = price[i-1] + rodCuttingRecursive(size-i, price, dp);
        ans = max(ans, remainingCost);
    }
    return  ans;
}

int rodCuttingBottomUp(vector<int> &price, int size){
    vector<int> dp(size+1, 0);
    for(int i = 1; i <= size; i++) {
        for(int k = 1; k <= i; k++) {
            dp[i] = max(dp[i], dp[i-k] + price[k-1]);
        }
    }
    
    return dp[size];
}

int main() {

    int len;
    vector<int> vec = {1, 5, 8, 9, 10, 17, 17, 20};
    len = vec.size();
    vector<int> dp(len, 0);
    cout << "top down output: " << rodCuttingRecursive(len, vec, dp) << endl;

    cout << "bottom up output: " << rodCuttingBottomUp(vec, len) << endl;



    return 0;
}