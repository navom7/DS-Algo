#include <iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<climits>

using namespace std;


string UniqueSubstring(string str){
    unordered_map<char,int> m;
    int i = 0, j = 0, len = 0;
    int mxl = INT_MIN;
    string subs;
    
    while(j < str.length()){
        char ch = str[j];
        
        if(m.count(ch) && m[ch] >= i) {
            len = (len - (j-i));
            i = m[ch]+1;
        }
        
        m[ch] = j;
        j++;
        len++;
        
        if(len > mxl){
            mxl = len;
            subs = str.substr(i, mxl);
        }
    }
    return subs;
}


int main() {
    string s;
    cin >> s;
    cout << UniqueSubstring(s) << endl;
    
    return 0;
}
