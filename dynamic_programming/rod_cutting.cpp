/* 

Given a list of prices for every length
and length of the rod

find out the maximum amount that can be made by breaking that rod into smaller length

prices = [1, 5, 8, 9, 10, 17, 17, 20]
Rod Length = 8

output 17 + 5 = 22
a length 2 and 6


*/


#include<bits/stdc++.h>
using namespace std;

int cutting_rod_top_down(vector<int> &vec, int len, vector<int> & dp){
    if(dp[len] != 0) {
        return dp[len];
    }
    if(len <= 0){
        return 0;
    }
    // cout << len << endl;
    int price = INT_MIN;
    for(int i = 0; i < len; i++){
        int temp_price = vec[i] + cutting_rod_top_down(vec, len-i-1, dp);
        price = max(price, temp_price);
    }
    return dp[len] = price;
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
    vector<int> vec = {1, 5, 8, 9, 10, 17, 17, 20};
    len = vec.size();
    vector<int> dp(len, 0);
    cout << "top down output: " << cutting_rod_top_down(vec, len, dp) << endl;

    cout << "bottom up output: " << rod_cutting_bottom_up(vec, len) << endl;

    return 0;
}
