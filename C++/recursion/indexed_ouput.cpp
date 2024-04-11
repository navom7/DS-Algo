/* 
Given n numbers of string of length k
print all the string where in every output string
the ith character is from ith input string

input:
n = 3
k = 2
ab
xy
mn

output:
axm
axn
aym
ayn
bxm
bxn
bym
byn

*/


#include<bits/stdc++.h>
using namespace std;

void print_in_order(vector<vector< char > > vec, int n, int k, int st, string output){
    if(st >= n){
        cout << output << endl;
        return;
    }
    for(int i = 0; i < k; i++){
        print_in_order(vec, n, k, st+1, output+vec[st][i]);
    }
    return;
}

int main(){
    int n, k; cin >> n >> k;
    vector<vector<char> > vec;
    for(int i = 0; i < n; i++){
        vector<char> temp;
        for(int m = 0; m < k; m++){
            char ch; cin >> ch;
            temp.push_back(ch);
        }
        vec.push_back(temp);
    }
    string output = "";
    print_in_order(vec, n, k, 0, output);


    return 0;
}
