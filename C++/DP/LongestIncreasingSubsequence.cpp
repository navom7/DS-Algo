#include<iostream>
#include<vector>

using namespace std;

int lis(vector<int> &arr, int n) {
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n-1];
}

int main() {

    vector<int> arr{1, 50, 2, 4, 10, 8, 30, 100};
    cout << lis(arr, arr.size()) << endl;

    return 0;
}