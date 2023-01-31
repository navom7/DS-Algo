// There is a ladder of n steps, you can take atmost k steps at once (from 1 to k steps).
// Find out in how many ways you can reach to the top

//This problem can also be treated like extended version of fibonacci series

#include<iostream>
using namespace std;

int n_ladder_top_down(int n, int k){
    if(n < 0)
        return 0;
    if(n == 0 || n == 1)
        return 1;
    int sum = 0;
    for(int i = 1; i <= k; i++){
        sum += n_ladder_top_down(n-i, k);
    }
    return sum;
}


int n_ladder_bottom_up(int n, int k){
    if(n < 0)
        return 0;
    int arr[n+1] = {0};
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i <= n; i++){
        int idx = 1;
        int temp = 0;
        while(idx <= k && (i-idx) >= 0){
            temp += arr[i-idx];
            idx++;
        }
        // cout << i << " " << temp << endl;
        arr[i] = temp;
    }
    return arr[n];
}


int main(){
    int n, k; cin >> n >> k;
    cout <<"N Ladder n_ladder_top_down ===========================> " << n_ladder_top_down(n, k) << endl;
    
    cout <<"N Ladder n_ladder_bottom_up ===========================> " << n_ladder_bottom_up(n, k) << endl;

    return 0;
}