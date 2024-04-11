#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

int trappedRain(vector<int> arr){
    int n = arr.size();
    if(n < 3)
        return 0;
    vector<int> left(n, arr[0]);
    vector<int> right(n, 0);
    right[n-1] = arr[n-1];
    
    for(int i = 1; i < n; i++){
        left[i] = max(arr[i], left[i-1]);
    }
    for(int i = n-2; i >= 0; i--){
        right[i] = max(arr[i], right[i+1]);
    }
    
    for(int i = 0; i < n; i++){
        cout << left[i] << " ";;
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout  << right[i] << " ";
    }
    
    int trappedWater = 0;
    for(int i = 0; i < n; i++){
        trappedWater += min(left[i], right[i])-arr[i];
    }
    return trappedWater;
}


int main(){
    vector<int> water = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trappedRain(water) << endl;
    
    return 0;
}
