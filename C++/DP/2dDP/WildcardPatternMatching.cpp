#include<iostream>
#include<vector>
using namespace std;

bool patternMatchingHelper(string pattern, string input, int i, int j) {
    int ps = pattern.size();
    int is = input.size();
    if(i == ps-1) {
        if(pattern[i] == "*") {
            return true;
        } else if(pattern[i] == '?') {
            if(j == is-1) {
                return true;
            } else {
                return false;
            }
        } 


    }
}

bool patternMatching(string s, string p){
     
    
}




int main() {
    string input = "baaabab";
    string pattern = "*****ba*****ab";

    cout << patternMatching(input, pattern) << endl;
}

for(auto x: veca) {
            cout << x << " ";
        } cout << endl;
        for(auto x: vecb) {
            cout << x << " ";
        } cout << endl;