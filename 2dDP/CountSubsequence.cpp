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

int main() {

    string a = "ABCECDG";
    string b = "ABC";

    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    cout << countSub(a, b, m-1, n-1, dp) << endl;

    for(auto x: dp) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}