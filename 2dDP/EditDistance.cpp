#include<iostream>
#include<vector>
using namespace std;

int editDistanceRecursive(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    int m = s1.size();
    int n = s2.size();
    if(i >= m) {
        return dp[i][j] = n-j;
    }
    if(j >= n) {
        return dp[i][j] = m-i;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int a = 0, b = 0, c = 0;
    if(s1[i] == s2[j]) {
        return dp[i][j] = editDistanceRecursive(s1, s2, i+1, j+1, dp);
    } else {
        a = 1 + editDistanceRecursive(s1, s2, i+1, j, dp);
        b = 1 + editDistanceRecursive(s1, s2, i, j+1, dp);
        c = 1 + editDistanceRecursive(s1, s2, i+1, j+1, dp);
        return dp[i][j] = min(a, min(c, b));
    }
}


int editDistance(string str1, string str2){
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    return editDistanceRecursive(str1, str2, 0, 0, dp);
}

int main() {
    string s1 = "sunday";
    string s2 = "saturday";

    cout << editDistance(s1, s2) << endl;

    return 0;
}