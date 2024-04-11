// You are given price of a stock over next n days, 
// your task is to calculate span of stock’s price for all n days.

// The span of the stock's price today is defined as the 
// maximum number of consecutive days (starting from today 
// and going backwards) for which the price of the stock was 
// less than or equal to today's price.

// For example, if the price of a stock over the next 7 days were 
// [100, 80, 60, 70, 60, 75, 85], then the stock spans would be 
// [1, 1, 1, 2, 1, 4, 6].


#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> v) {
//Write your code here. Do not modify the function or parameters.
    int n = v.size();
    stack<pair<int, int>> st;
    vector<int> resArr;
    
    for(int i = 0; i < n; i++) {
        if(st.empty()) {
            resArr.push_back(1);
            st.push(make_pair(i, 1));
        } else {
            int cnt = 1;
            while(!st.empty()){
                pair<int,int> pr = st.top();
                if(v[i] < v[pr.first])
                    break;
                st.pop();
                cnt += pr.second;
            }
            resArr.push_back(cnt);
            st.push(make_pair(i, cnt));
        }
    }
    return resArr;
}