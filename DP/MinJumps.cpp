#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int minJumpsTopDown(vector<int> &jumpList, int i, int n, vector<int> &dp) {
    if(i >= n) {
        return 0;
    }
    if(dp[i] != 0) {
        return dp[i];
    }
    int incurredCost = INT_MAX;
    for(int jump = 1; jump <= jumpList[i]; jump++) {
        int currentCost = minJumpsTopDown(jumpList, i+jump, n, dp);
        incurredCost = min(incurredCost, currentCost + 1);
    }

    return dp[i] = incurredCost;
}

int main() {
    int len;
    vector<int> vec = {3,4,2,1,2,3,10,1,1,1,2,5};
    len = vec.size();
    vector<int> dp(len+1, 0);
    cout << "top down output: " << minJumpsTopDown(vec, 0, len, dp) << endl;
    for(auto x: dp) {
        cout << x << " ";
    }
    // cout << "bottom up output: " << rod_cutting_bottom_up(vec, len) << endl;
    

    return 0;
}