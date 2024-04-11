#include<iostream>
#include<vector>

using namespace std;

int countWays(int n, int k) {
    if(n == 0) {
        return 1;
    }
    if(n < 0) {
        return 0;
    }
    int ans = 0;
    for(int i = 1; i <= k; i++) {
        ans += countWays(n-i, k);
    }
    return ans;
}

int countWaysTPDP(int n, int k, int *dp) {
    if(n == 0) {
        return 1;
    }
    if(n < 0) {
        return 0;
    }
    if(dp[n] != 0) {
        return dp[n];
    }
    int ans = 0;
    for(int i = 1; i <= k; i++) {
        ans += countWays(n-i, k);
    }
    return dp[n] = ans;
}

int countWaysBUDP(int n, int k, int *dp) {
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if((i-j) < 0) 
                continue;
            dp[i] += dp[i-j];
        }
    }
    return dp[n];
}

int countWaysBUDPOptimised(int n, int k, int *dp) {
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        int a;
        if(i-k-1 < 0) {
            a = 0;
        } else {
            a = dp[i-k-1];
        }
        cout << i << ": " << a << " " << dp[i-1] << endl;
        dp[i] = 2*dp[i-1] - a;
    }
    return dp[n];
}

int main() {
    int n; cin >> n;
    int k; cin >> k;
    cout << "countWays: " << countWays(n, k) << endl;;

    int dp[1000] = {0};
    cout << "countWaysTPDP: " << countWaysTPDP(n, k, dp) << endl;

    int dp2[1000] = {0};
    cout << "countWaysBUDP: " << countWaysBUDP(n, k, dp2) << endl;

    int dp3[1000] = {0};
    cout << "countWaysBUDPOptimised: " << endl << countWaysBUDPOptimised(n, k, dp3) << endl;

    return 0;
}