//Find out squared root of n upto p digits.

#include <bits/stdc++.h>
using namespace std;

float SquaredRoot(int n, int p){
    if(n == 0){
        return 0;
    }
    float ans = 0.0;
    int s = 0;
    int e = n;
    // cout << ans << endl;
    
    //Squared root for integer part
    while(s <= e){
        int mid = (s+e)/2;
        if(mid*mid == n){
            return mid;
        } else if(mid*mid < n){
            ans = mid + 0.0;
            s = mid + 1;
        } else {
            e = mid-1;
        }
    }
    // cout << ans;
    
    //For Decimal digits until p digit
    float dig = 0.1;
    for(int i = 0; i <p; i++){
        while(ans*ans < n){
            ans += dig;
        }
        // cout << ans << endl;
        ans -= dig;
        dig = dig/10;
    }
    
    return ans;
    
}


int main() {
    int n; cin >> n;
    int k; cin >> k;
    cout << SquaredRoot(n, k) << endl;
    
    return 0;
}
