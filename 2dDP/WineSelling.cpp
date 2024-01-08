#include<iostream>
#include<vector>

using namespace std;

//top down dp code
int wines(int dp[][10], int arr[], int l, int r, int yr) {
    if(l > r) {
        return 0;
    }
    if(dp[l][r] != 0) {
        return dp[l][r];
    }
    int lC = arr[l]*yr + wines(dp, arr, l+1, r, yr+1);
    int rC = arr[r]*yr + wines(dp, arr, l, r-1, yr+1);

    return dp[l][r] = max(lC, rC);

}


//bottom up dp code
int winesBU(int prices[], int N) {
    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));

    for(int i = N-1; i >= 0; i--) {
        for(int j = 0; j < N; j++) {
            if(j >= i) {
                int yr = N - (j-i);
                int pickBottom = yr * prices[i] + dp[i+1][j];
                int pickLeft = yr * prices[j] + dp[i][j-1];
                dp[i][j] = max(pickBottom, pickLeft);
            }
        }
    }
    cout << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << dp[i][j] << " ";
            if(dp[i][j]/10 == 0) {
                cout << " ";
            }
        }
        cout << endl;
    }

    // cout << dp[0][N-1];
    return dp[0][N-1];

}

int main() {

    int a[] = {2,3,5,1,4};
    int n = 5;
    int dp[10][10] = {0};

    cout << wines(dp, a, 0, n-1, 1) << endl;

    cout << "bottom Up: " << winesBU(a, n) << endl;

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}