#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


void Subsequence(string i, string o, vector<string> &v){
    if(i.size() == 0){
        v.push_back(o);
        return;
    }
    char ch = i[0];
    string ss = i.substr(1);
    Subsequence(ss, o+ch, v);
    
    Subsequence(ss, o, v);
}
bool compare(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    } else {
        return a.length() < b.length();
    }
}

int main() {
    string s1;
    cin >> s1;
    vector<string> vec;
    string o;
    Subsequence(s1, o, vec);
    
    sort(vec.begin(), vec.end(), compare);
    
    for(auto x : vec){
        cout << "'" << x << "', ";
    }
    
    return 0;
}



