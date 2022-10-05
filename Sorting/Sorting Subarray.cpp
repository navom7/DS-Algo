// Write a function that takes in an array and returns two integers, denoting starting and ending indices of the smallest subarray in the input array that needs to be sorted in place so that the entire input is sorted.

// If the input array is already sorted, return a pair [-1,-1].

// Sample Input

// [0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29]
// Sample Output

// [4,6]
// Explanation

// If we sort the subarray [10, 11, 7] then entire array becomes sorted.


#include<bits/stdc++.h>
using namespace std;


pair<int,int> subarraySorting(vector<int> a){
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function
    int n = a.size();
    if(n < 2){
        return {-1, -1};
    }
    int mn = INT_MAX;
    int mx = INT_MIN;
    
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(a[i] > a[i+1]){
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
        } else if(i == n-1){
            if(a[i] < a[i-1]){
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
        } else {
            if((a[i] > a[i+1] && a[i] > a[i-1]) || (a[i] < a[i-1] && a[i] < a[i+1])){
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
        }
    }
    
    int x = -1, y = -1;
    for(int i = 0; i < n; i++){
        if(a[i] <= mn){
            continue;
        } else {
            x = i;
            break;
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(a[i] >= mx){
            continue;
        } else {
            y = i;
            break;
        }
    }
    
    return {x, y};
}
