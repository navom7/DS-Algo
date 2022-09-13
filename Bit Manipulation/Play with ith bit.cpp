#include <iostream>
using namespace std;

int getIthBit(int n, int i){
    int mask = (1 << i);
    if(n & mask){
        return 1;
    } else {
        return 0;
    }
}
void setIthBit(int &n, int i){
    int mask = (1 << i);
    n = n | mask;
}

void clearIthBit(int &n, int i){
    int mask = (1<<i);
    mask = ~mask;
    n = n&mask;
}

void UpdateIthBitWithValue(int &n, int i, int v){
    clearIthBit(n, i);
    int mask = (v<<i);
    n = (n|mask);
}
void ClearLastiBits(int &n, int i){
    int mask = (-1 << i);
    n = n&mask;
}

void clearBitsInRange(int &n, int i, int j){
    int a = (~0)<<(j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    n = n&mask;
}

int main() {
    int n, i, v;
    cin >> n >> i >> v;
    cout << getIthBit(n, i)<< endl;
    setIthBit(n, i);
    cout << n << endl;
    clearIthBit(n, i);
    cout << n << endl;
    cout << n << endl;
    
    UpdateIthBitWithValue(n, i, v);
    
    ClearLastiBits(n, i);
    
    clearBitsInRange(n, i, v);
    
    cout << n << endl;
}
