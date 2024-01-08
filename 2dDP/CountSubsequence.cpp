#include<iostream>
#include<vector>

using namespace std;

int countSub(string a, string b, int m, int n, vector<vector<int>> &dp) {
    if((m == -1 && n == -1) || n == -1) {
        return 1;
    }
    if(m == -1) {
        return 0;
    }

    if(dp[m][n] != 0) {
        return dp[m][n];
    }

    if(a[m] != b[n]) {
        return dp[m][n] = countSub(a, b, m-1, n, dp);
    } else {
        return dp[m][n] = countSub(a, b, m-1, n, dp) + countSub(a, b, m-1, n-1, dp);
    }
}

int countSubBottomUpd(string a, string b) {

    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(auto x: dp) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return dp[m][n];

}

int main() {

    string a = "ABCECDGCCABMNCC";
    string b = "ABC";

    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    cout << "count Sub Top Down: " << endl << countSub(a, b, m-1, n-1, dp) << endl;

    for(auto x: dp) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }


    cout << "count Subsequnce Bottom Up: " << endl << countSubBottomUpd(a, b) << endl;

    return 0;
}