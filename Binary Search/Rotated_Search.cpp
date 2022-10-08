#include <bits/stdc++.h>
using namespace std;

int rotatedSearch(vector<int> &arr, int n, int k){
    if(n == 0){
        return -1;
    }
    int ans;
    int s = 0;
    int e = n-1;
    
    while(s <= e){
        int mid = (s+e)/2;
        if(arr[mid] == k){
            return mid;
        }
        if(arr[mid] >= arr[s]){
            if(k >= arr[s] && k < arr[mid]){
                e = mid-1;
            } else {
                s = mid+1;
            }
        } else {
            if(k <= arr[e] && k > arr[mid]){
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
    }
    return -1;
    
}


int main() {
    vector<int> vec{7, 8, 9, 10, 0, 1, 2, 3, 4};
    int n = vec.size();
    int k; cin >> k;
    cout << rotatedSearch(vec, n, k) << endl;
    
    return 0;
}
