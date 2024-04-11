//Find x to the power n in O(log N) time complexity

#include<bits/stdc++.h>
using namespace std;

int powerOfN(int a, int n){
    if(n == 0){
        return 1;
    }
    
    int p = a;
    int ans = 1;
    while(n) {
        // cout << n << " " << p << endl;
        if(n&1){
            ans = ans*p;
        }
        
        p = p*p;
        n = (n >> 1);
    }
    return ans;
}

int main(){
    cout << powerOfN(2, 5);
    
    return 0;
}
