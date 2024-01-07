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

int main() {

    int a[] = {2,3,5,1,4};
    int n = 5;
    int dp[10][10] = {0};

    cout << wines(dp, a, 0, n-1, 1) << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}