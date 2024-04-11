#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

int largestBand(vector<int> arr){
    int n = arr.size();
    if(n < 2)
        return n;
        int cs = 0, ms = 0;
    unordered_set<int> st;
    for(auto x : arr){
        st.insert(x);
    }
    for(auto k : st){
        int x = k;
        cs = 1;
        if(st.find(x-1) != st.end()){
            continue;
        }
        if(st.find(x+1) != st.end()){
            while(st.find(x+1) != st.end()){
                cs++; x++;
            }
        }
        if(ms < cs)
            ms = cs;
    }
    return ms;
}


int main(){
    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << largestBand(arr) << endl;
    
    return 0;
}
