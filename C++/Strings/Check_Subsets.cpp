#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


bool isSubs(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    
    int i = 0, j = 0;
    while(i < n && j < m){
        if(s1[i] == s2[j]){
            cout << s1[i] << " ";
            i++; j++;
        } else 
            i++;
    }
    cout << endl;
    return j == m;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    cout << "is Subsequence: " << isSubs(s1, s2) << endl;
    
    return 0;
}




