#include <iostream>
using namespace std;

int countSetBits(int n){
    int cnt = 0;
    while(n){
        if(n&1){
            cnt++;
        }
        n = (n>>1);
    }
    return cnt;
}

int countsetBitsFaster(int n){
    int ans = 0;
    while(n){
        ans++;
        n = (n&(n-1));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    cout << countSetBits(n) << endl << countsetBitsFaster(n) << endl;
}
