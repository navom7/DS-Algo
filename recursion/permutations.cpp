#include<bits/stdc++.h>
using namespace std;

void printPermutations(string &str, int l, int r) {
    if(l == r){
        cout << str << endl;
    } else {
        for(int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            printPermutations(str, l+1, r);
            swap(str[l], str[i]);
        }
    }
}


int main() {
    string str = "abc";
    int n = str.size();
    printPermutations(str, 0, n-1);
    return 0;
}