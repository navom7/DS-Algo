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

int main() {

    int n; cin >> n;


    int dp[100] = {0};
    cout << countBSTTopDOwn(n, dp) << endl;

    cout << countTrees(n) << endl;

    return 0;
}