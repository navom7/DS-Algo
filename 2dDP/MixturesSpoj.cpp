#include<iostream>
#include<vector>

using namespace std;

long long helperSmoke(vector<int> v, int i, vector<int> &dp) {
    int n = v.size();
    // cout << i << " " << n << endl;
    // for(auto x: v) {
    //     cout << x << " ";
    // }
    // cout << endl;
    if(i >= n-1 || n <= 2) {
        if(n == 1) {
            return dp[0] = 0;
        } else if(n == 2) {
            return dp[1] = v[0]*v[1];
        } else {
            int smoke = v[n-1]*v[n-2];
            int newColor = (v[n-1] + v[n-2])%100;
            v.erase(v.begin() + n-1);
            v[n-2] = newColor;
            return dp[n-2] = smoke + helperSmoke(v, 0, dp);
        }
    }
    if(dp[i] != 0)
        return dp[i];
    int a = 0, b = 0;
    vector<int> temp = v;
    int aSmoke = temp[i]*temp[i+1];
    int newColourA = (temp[i] + temp[i+1])%100;
    temp.erase(temp.begin() + i);
    temp[i] = newColourA;
    a = aSmoke + helperSmoke(temp, i, dp);
    
    b = helperSmoke(v, i+1, dp);

    cout << a << " " << b << endl;
    
    return dp[i] = min(a,b);
}

long long minimumSmoke(vector<int> v){

    vector<int> dp(v.size() + 1, 0);

    return helperSmoke(v, 0, dp);
}


int main() {
    vector<int> v = {40, 60, 20, 80};
    
    

    cout << minimumSmoke(v) << endl << endl;




    // vector<int> vec;

    // for(int i = 0; i < 10; i++) {
    //     vec.push_back(i);
    // }
    // cout << vec.size() << endl;

    // for(auto x: vec) {
    //     cout << x << " ";
    // } 
    // cout << endl;

    // vec.erase(vec.begin() + 4);

    // cout << vec.size() << endl;

    // for(auto x: vec) {
    //     cout << x << " ";
    // } 
    // cout << endl;

    return 0;
}