// There is a ladder of n steps, you can take atmost k steps at once (from 1 to k steps).
// Find out in how many ways you can reach to the top

//This problem can also be treated like extended version of fibonacci series

#include<iostream>
using namespace std;

int n_ladder_top_down(int n, int k, int *dp){
    if(n < 0)
        return 0;
    if(n == 0 || n == 1)
        return 1;
    
    if(dp[n] != 0)
        return dp[n];
    int sum = 0;
    for(int i = 1; i <= k; i++){
        sum += n_ladder_top_down(n-i, k, dp);
    }
    return dp[n] = sum;
}


int n_ladder_bottom_up(int n, int k){
    if(n < 0)
        return 0;
    int arr[n+1] = {0};
    arr[0] = 1; 
    for(int i = 1; i <= n; i++){
        for(int jump = 1; jump <= k; jump++){
            if(i-jump >= 0){
                arr[i] += arr[i-jump];
            }
        }
    }
    return arr[n];
}



int n_ladder_bottom_up_optimized(int n, int k){
    if(n < 0)
        return 0;
    int dp[n+1] = {0};
    dp[0] = 1; 

    for(int i = 1; i <= k; i++){
        for(int idx = 0; idx < i; idx++){
            dp[i] += dp[idx];
        }
    }

    for(int i = k+1; i <= n; i++){
        dp[i] = 2*dp[i-1] - dp[n-k-1];
    }
    return dp[n];
}



int main(){
    int n, k; cin >> n >> k;
    int dp[n+1] = {0};
    cout <<"N Ladder n_ladder_top_down ===========================> " << n_ladder_top_down(n, k, dp) << endl;
    
    cout <<"N Ladder n_ladder_bottom_up ===========================> " << n_ladder_bottom_up(n, k) << endl;
    cout <<"N Ladder n_ladder_bottom_up ===========================> " << n_ladder_bottom_up_optimized(n, k) << endl;

    return 0;
}