/* 




*/


#include<bits/stdc++.h>
using namespace std;

int min_jumps_top_down(vector<int> &vec, int st, int len, vector<int> & dp){
    if(dp[st] != 0) {
        return dp[st];
    }
    if(st >= len){
        return 1;
    }
    // cout << len << endl;
    int jumps = INT_MAX;
    for(int i = 1; i <= vec[st]; i++){
        jumps = min(jumps, min_jumps_top_down(vec, st+i, len, dp));
    }
    cout << jumps << " ";
    return dp[st] = jumps;
}

int rod_cutting_bottom_up(vector<int> & vec, int len) {
    vector<int> dp(len+1, 0);
    if(len == 0) {
        return 0;
    }
    for(int i = 1; i <= len; i++) {
        for(int idx = 1; idx <= i; idx++) {
            int temp = dp[i-idx] + vec[idx-1];
            cout << temp << ", " << vec[i-1] << " => ";
            dp[i] = max(temp, dp[i]);
            cout << i << " " << dp[i] << endl;
        }
        
    }
    return dp[len];
}




int main(){
    int len;
    vector<int> vec = {3,4,2,1,2,3,10,1,1,1,2,5};
    len = vec.size();
    vector<int> dp(len+1, 0);
    cout << "top down output: " << min_jumps_top_down(vec, 0, len, dp) << endl;

    // cout << "bottom up output: " << rod_cutting_bottom_up(vec, len) << endl;

    return 0;
}
