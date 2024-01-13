#include<iostream>
#include<vector>
#include<climits>

using namespace std;

long long smoke(int s, int e, vector<int> &v) {
    long long ans = 0;
    for(int i = s; i <= e; i++) {
        ans += v[i];
    }
    return ans%100;
}

long long helperSmoke(vector<int> v, int i, int j, vector<vector<long long>> &dp) {
    
    if(i >= j) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;
    for(int k = i; k <= j; k++) {
        dp[i][j] = min(dp[i][j], helperSmoke(v, i, k, dp) + helperSmoke(v, k+1, j, dp) + smoke(i, k, v) * smoke(k+1, j, v));
    }
    return dp[i][j];
    
}

long long minimumSmoke(vector<int> v){
    int n = v.size();
    vector<vector<long long>> dp(n, vector<long long>(n, -1));

    return helperSmoke(v, 0, n-1, dp);
}


int main() {
    vector<int> v = {41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 91, 95, 42, 27, 36, 91, 4, 2, 53, 92, 82, 21, 16, 18, 95, 47, 26, 71, 38, 69, 12, 67, 99, 35, 94, 3, 11, 22, 33, 73, 64, 41, 11, 53, 68, 47, 44, 62, 57, 37, 59, 23, 41, 29, 78, 16, 35, 90, 42, 88, 6, 40, 42, 64, 48, 46, 5, 90, 29, 70, 50, 6, 1, 93, 48, 29, 23, 84, 54, 56, 40, 66, 76, 31, 8, 44, 39, 26, 23, 37, 38, 18, 82, 29, 41};
    
    

    cout << minimumSmoke(v) << endl << endl;




    // vector<int> vec;

    // for(int i = 0; i < 10; i++) {
    //     vec.push_back(i);
    // }
    // cout << vec.size() << endl;

    // for(auto x: vec) {
    //     cout << x << " ";
    // } 
    // cout << endl;

    // vec.erase(vec.begin() + 4);

    // cout << vec.size() << endl;

    // for(auto x: vec) {
    //     cout << x << " ";
    // } 
    // cout << endl;

    return 0;
}