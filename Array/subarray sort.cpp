#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>


using namespace std;

pair<int,int> SubArraySort(vector<int> arr){
    int n = arr.size();
    if(n < 2){
        return make_pair(-1, -1);
    }
    if(n == 2){
        if(arr[0] > arr[1]){
            return make_pair(0, 1);
        } else {
            return make_pair(-1, -1);
        }
    }
    int mn = INT_MAX;
    int mx = INT_MIN;
    int p = 0, q = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(arr[i] > arr[i+1]){
                mn = min(arr[i], mn);
                mx = max(arr[i], mx);
            }
            continue;
        }else if(i == n-1){
            if(arr[i] < arr[i-1]){
                mn = min(arr[i], mn);
                mx = max(arr[i], mx);
            }
        } else {
            if(!(arr[i] > arr[i-1]) || !(arr[i] < arr[i+1])){
                mn = min(arr[i], mn);
                mx = max(arr[i], mx);
            }
        }
        
    }
    for(int i = 0; i < n; i++){
        if(arr[i] > mn){
            p = i;
            break;
        }
        
    }
    for(int i = 0; i < n; i++){
        if(arr[n-i-1] < mx){
            q = n-i-1;
            break;
        }
        
    }
    cout << mn << " " << mx << endl;
    return make_pair(p, q);
}


int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto x = SubArraySort(arr);
    cout << x.first << " " << x.second << endl;
    return 0;
}
