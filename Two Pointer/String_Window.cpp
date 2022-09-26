#include <iostream>
#include<unordered_map>
#include<string>
#include<climits>
using namespace std;


string StringWindow(string s, string p){
    int n = s.size();
    int m = p.size();
    unordered_map<char, int> sm;
    unordered_map<char, int> pm;
    for(auto x : p){
        pm[x]++;
    }
    int cnt = 0;
    int minLen = INT_MAX;
    int len = 0;
    int i = 0, j = 0;
    
    string ans = "";
    while(j < n){
        char ch = s[j];
        sm[ch]++;
        
        if((pm[ch] != 0) && (pm[ch] >= sm[ch])){
            // cout << ch << " " << pm[ch] << " " << sm[ch] << endl << endl;
            cnt++;
        }
        // cout << "ch =>" << ch << " cnt =>" << cnt << endl;;
        if(cnt == m){
            // cout<<"Nanhe " << endl;
            while(pm[s[i]] == 0 || sm[s[i]] > pm[s[i]]){
                sm[s[i]]--;
                i++;
            }
            len = (j-i)+1;
            if(len < minLen){
                minLen =  len;
                ans = s.substr(i, len);
            }
        }
        j++;
    }
    return ans;
}

int main() {
    string s, p;
    cin >> s >> p;
    
    cout << "Shortest Window is: " << StringWindow(s, p) << endl;
    
    
    return 0;
}
