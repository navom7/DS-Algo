#include<bits/stdc++.h>
using namespace std;

bool isRedundant(string exp) {
    stack<char> st;
    for(auto x: exp) {
        if(x != ')') {
            st.push(x);
        } else {
            bool operator_found = false;
            while(!st.empty() && st.top() != '(') {
                char tp = st.top();
                if(tp == '*' || tp == '/' || tp == '-' || tp == '+' )
                    operator_found = true;
                st.pop();
            }
            st.pop();
            if(operator_found == false)
                return true;
        }

    }
    return false;
}

int main(){
    string expr = "[(a+b)*d((c-r))]*(b-a)";
    cout << isRedundant(expr) << endl;
}