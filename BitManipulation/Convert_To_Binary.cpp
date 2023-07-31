#include <iostream>
using namespace std;

int convertToBinary(int n){
    int ans = 0;
    int p = 1;
    while(n){
        if(n&1){
            ans = p + ans;
        }
        p = p*10;
        n = (n >> 1);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    cout << convertToBinary(n) << endl;
}
