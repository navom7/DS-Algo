#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string exp) {
    stack<char> st;
    for(auto x: exp) {
        if(x == '{' || x == '(' || x == '[') {
            st.push(x);
        } else if(x == '}') {
            if(!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                return false;
            }
        } else if(x == ']') {
            if(!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                return false;
            }
        } else if(x == ')') {
            if(!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                return false;
            }
        } 
    }
    return st.empty();
}

int main(){
    string expr = "[(a+b)*d(c-r)]*(b-a)";
    cout << isBalanced(expr) << endl;
}