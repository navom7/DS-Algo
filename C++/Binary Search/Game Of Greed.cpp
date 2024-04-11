// You are playing a game with your 'k' friends. You have an array of N coins, at each index i you have a coin of value a[i].
// Your task is to divide the coins, among a group of K friends by doing consecutive segments (k-subarrays) of the array.
// Each friend will get a total sum of the coins in that subarray. Since all your friends are greedy, and they will pick the largest k-1 segments and you will get the smallest segment. Find out the maximum value you can make by making an optimal partition.

// Note : The coins array may or may not be sorted!

// Input
// K = 3
// coins = {1,2,3,4};

// Output
// 3

// Explanation 
// The ideal partition looks like this -

// {1 + 2} = 3
// {3} = 3
// {4} = 4

// You will get a maximum of 3 coins in the best case.




#include<bits/stdc++.h>
using namespace std;


int getCoins(vector<int> arr, int k){
    //return the max coins that you can win!
    for(auto x : arr){
        cout << x << " ";
    }
    cout << endl;
    // sort(arr.begin(), arr.end());
    int n = arr.size();
    int s = arr[0];
    int e = 0;
    for(auto x : arr){
        e += x;
    }
    int ans = INT_MIN;
    while(s <= e){
        int mid = (s+e)/2;
        int cnt = 0;
        int sum = 0;
        for(auto x : arr){
            // cout << x << " ";
            sum += x;
            if(sum >= mid){
                cnt++;
                sum = 0;
            }
        }
        cout << endl << mid  << "  " << cnt << endl;
        if(cnt >= k){
            s = mid+1;
            ans = max(mid, ans);
        } else {
            e = mid-1;
        }
    }
    return ans;
    
}
