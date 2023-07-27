// First Non-Repeating Character
// Given a stream of characters (lowercase alphabets), find the first non-repeating character from stream. You need to tell the first non-repeating character in O(1) time at each index. If for a current index there is no such character return '0' for that particular index.

// Input Format:

// A String S of length N passed as a parameter to the given function.

// Output Format:

// Return a vector of characters of length N where V[i] character represents first non-repeating character from S[0] to S[i].

// Constraints:

// 1<=N<=100

// Expected time complexity:

// O(N) where N is the total number of input characters in one testcase. (Use the property of queue)



// Sample Testcase :

// Input:

// aabcbcd

// Output:

// a 0 b b c 0 d

#include<bits/stdc++.h>
using namespace std;


vector<char> FindFirstNonRepeatingCharacter(string S){
    cout << "input: " << S << endl;
    vector<char> ch;
    unordered_map<char,int> mp;
    queue<char> st;
    for(auto x: S) {
        cout << x << ": --> ";
        if(st.empty()) {
            st.push(x);
            if(mp[x] == 0)
                ch.push_back(x);
            else
                ch.push_back('0');
            mp[x] += 1;
        } else if(st.front() == x) {
            cout << st.front() << " " << x << " " << mp[x] << " ";
            mp[x] += 1;
            cout << mp[x] << " ";
            while(mp[st.front()] >= 2) {
                cout << "popping " << st.front() << " ";
                st.pop();
            }
            cout << " is st empty?: " << st.empty() << " ";
            if(st.empty()) {
                ch.push_back('0');
            } else {
                cout << st.front() << endl;
                ch.push_back(st.front());
            }
        } else {
            ch.push_back(st.front());
            if(mp[x] >= 1) {
                mp[x] += 1;
            } else {
                st.push(x);
                mp[x] += 1;
            }
        }
        cout << "      output: ";
        for(auto mpr: ch) {
            cout << mpr << " ";
        }
        cout << endl;
    }
    return ch;
}


void printFirstNRC() {
    char c;
    cin >> c;
    int mp[27] = {0};
    queue<char> q;
    while(c != '.') {
        int num = c - 'a';
        mp[num] += 1;
        q.push(c);
        while(!q.empty()) {
            if(mp[q.front() - 'a'] >= 2) {
                q.pop();
            } else {
                cout << "   " << q.front() << endl;
                break;
            }
        }
        if(q.empty()) {
            cout << "  0" << endl;
        }
        cin >> c;
    }
}

int main() {
    printFirstNRC();

    return 0;
}