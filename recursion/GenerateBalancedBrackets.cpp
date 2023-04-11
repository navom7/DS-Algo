// generate balanced n brackets


#include<bits/stdc++.h>
using namespace std;

void generateBalancedBrackets(int opn, int clz, string output, int n) {
    if(output.size() == 2*n && opn == clz) {
        cout << output << endl;
        return;
    } else if(output.size() > 2*n) {
        return;
    }
    if(opn > clz) {
        generateBalancedBrackets(opn, clz+1, output + ')', n);
    }
    if(opn < n) {
        generateBalancedBrackets(opn+1,clz, output + '(', n);
    }
}

int main() {
    string output = "";
    cout << endl;
    generateBalancedBrackets(0,0, output, 3);
}
