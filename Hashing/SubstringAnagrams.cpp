
// Given an string, 
// find all the possible pairs of anagrams 
// from all of substring of this string.

// Input : abba
// Output: 4


#include<iostream>
#include<map>
#include<vector>

using namespace std;

vector<int> getHashedValue(string s, int i, int j) {
    vector<int> freq(26,0);
    for(int k = i; k<= j; k++) {
        char ch = s[k];
        int pos = ch - 'a';
        freq[pos]++;
    }
    return freq;
}

void subStringAnagrams(string str) {
    int n = str.size();
    int ans = 0;
    map<vector<int>, int> mp;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            vector<int> freq = getHashedValue(str, i, j);
            mp[freq]++;
        }
    }
    for(auto x: mp) {
        int count = x.second;
        ans += (count*(count-1)/2);
    }
    cout << ans << endl;
}

int main() {
    string str;
    cin >> str;
    subStringAnagrams(str);

    return 0;
}