//First Non repeating character
#include<bits/stdc++.h>
using namespace std;

void firstNonRpt(string exp) {
    vector<char> ch;
    queue<char> st;
    for(auto x: exp) {
        if(st.empty()) {
            st.push(x);
            ch.push_back(x);
        } else {
            cout << x << " " << st.front() << endl;
            if(st.front() == x) {
                st.pop();
            }
            if(st.empty()) {
                ch.push_back('0');
            } else {
                st.push(x);
                ch.push_back(st.front());
            }
        }
    }
    cout << endl;
    for(auto x: ch) {
        cout << x << " ";
    }
}
int main(){
    
    string expr = "aabcbcd";

    firstNonRpt(expr);

}