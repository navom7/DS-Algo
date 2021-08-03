#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<int> longestChain(vector<int> arr) {
    int n = arr.size();
    unordered_set<int> st;
    vector<int> res;
    int longest = 0;
    for(auto x : arr) {
        st.insert(x);
    }
    for(auto x : arr) {
        vector<int> temp;
        int cnt = 0;
        if(st.find(x-1) != st.end()) {
            continue;
        } else {
            while(st.find(x) != st.end()) {
                temp.push_back(x);
                x++; cnt++;
            }
            if(cnt > longest) {
                longest = cnt;
                res = temp;
            }
        }
    }
    return res;
}


int main() {
    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    vector<int> temp = longestChain(arr);
    for(auto x : temp) {
        cout << x << " ";
    }

    return 0;
}