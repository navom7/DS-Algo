#include<iostream>
#include<string>

using namespace std;

int lcs(string s1, string s2, int i, int j, int n1, int n2, vector<vector<int>> &dp) {
    if(i == s1.length() || j == s2.length())
        return 0;

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(s1[i] == s2[j]) {
        return dp[i][j] = 1 + lcs(s1, s2, i+1, j+1, n1, n2, dp);
    }

    int a = lcs(s1, s2, i+1, j, n1, n2, dp);
    int b = lcs(s1, s2, i, j+1, n1, n2, dp);

    return dp[i][j] = max(a,b);
    
}


int main() {
    string s1 = "ABCD";
    string s2 = "ABEDG";
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));
    cout << lcs(s1, s2, 0, 0, n1, n2, dp) << endl;

    for(auto x: dp) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}