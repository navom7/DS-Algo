#include <iostream>
#include<vector>

using namespace std;

vector<pair<int,int> > housing(vector<int> &vec, int k){
    int i = 0;
    int j = 0;
    vector<pair<int,int>> res;
    int n = vec.size();
    int sum = 0;
    // cout << n << " k = " << k << endl;
    while(j < n){
        if(i == j){
            sum = vec[i];
            j++;
            if(j< n)
                sum += vec[j];
        } else {
            // cout << sum << endl;
            // cout << vec[i] << " " << vec[j] << endl;
            
            if(sum == k){
                res.push_back({i, j});
                sum -= vec[i];
                // cout << i << " " << j << endl;
                i++;j++;
                sum += vec[j];
            } else if(sum > k){
                sum -= vec[i];
                i++;
            } else {
                j++;
                sum += vec[j];
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr{ 1 ,3 ,2 ,1 ,4 ,1 ,3 ,2 ,1 ,1};
    int k = 8;
    vector<pair<int,int>> res = housing(arr, k);
    
    for(auto x : res){
        cout << x.first << " " << x.second << endl;
    }
    
    return 0;
}
