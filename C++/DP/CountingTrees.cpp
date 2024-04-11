#include<iostream>
#include<vector>

using namespace std;

int countTrees(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x = countTrees(i-1);
        int y = countTrees(n-i);
        ans += (x*y);
    }
    return ans;
}

int countBSTTopDOwn(int n, int dp[]) {
    if(n == 0 || n == 1) {
        return 1;
    }
    if(dp[n] != 0) {
        return dp[n];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x = countBSTTopDOwn(i-1, dp);
        int y = countBSTTopDOwn(n-i, dp);
        ans += (x*y);
    }
    return dp[n] = ans;
}

int countBSTBottomUp(int N) {
    vector<int> dp(N+1, 0);
    dp[1] = dp[0] = 1;
    for(int n = 2; n <= N; n++) {
        for(int j = 1; j <= n; j++) {
            dp[n] += dp[j-1]*dp[n-j];
        }
    }
    return dp[N];
}

int main() {

    int n; cin >> n;


    int dp[100] = {0};
    cout << countBSTTopDOwn(n, dp) << endl;

    cout << countTrees(n) << endl;

    cout << countBSTBottomUp(n) << endl;

    return 0;
}