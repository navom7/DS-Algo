// Given a string, find the smallest window (substring) which contains all distinct characters of the given input string.

// Sample Inputs

// aabcbcdbcaaad
// aaaa
// Sample Outputs

// dbca
// a
// Explanation : The smallest window is "dbca" as it contains all the distinct letters from input string. Similarly for the second case the answer should be 'a'.



#include<string>
#include<set>
#include<bits/stdc++.h>
using namespace std;

string stringWindow(string a, string b){
    unordered_map<char, int> am;
    unordered_map<char,int> bm;
    for(auto x: b){
        bm[x]++;
    }
    int sz = b.size();
    int n = a.size();
    int cnt = 0;
    int j = 0;
    int minLen = INT_MAX;
    string res = "";
    
    for(int i = 0; i < n; i++){
        char ch = a[i];
        am[ch]++;
        if(bm[ch] > 0 && bm[ch] >= am[ch]){
            cnt++;
        } 
        if(cnt == sz){
            while(bm[a[j]] < 1 || bm[a[j]] < am[a[j]]){
                am[a[j]]--;
                j++;
            }
            int len = (i-j)+1;
            if(len < minLen){
                minLen = len;
                res = a.substr(j, len);
            }
        }
    }
    return res;
}

string smallestWindow(string str){
    set<char> st;
    for(auto x : str){
        st.insert(x);
    }
    string s = "";
    for(auto x : st){
        s += x;
    }
    return stringWindow(str, s);
    
}
