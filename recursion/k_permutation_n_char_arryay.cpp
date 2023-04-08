// Print all possible strings of length k that can be formed from a set of n characters
// {'a', 'b'}, k = 3
// aaa
// aab
// aba
// abb
// baa
// bab
// bba
// bbb
#include<bits/stdc++.h>

using namespace std;

void generateStrings(vector<char>& chars, int k, string str) {
    if (k == 0) { // base case: if the length of the string is k
        cout << str << endl; // print the string
    }
    else {
        for (int i = 0; i < chars.size(); i++) {
            string newStr = str + chars[i]; // append the current character to the string
            generateStrings(chars, k - 1, newStr); // recursive call to generate strings of length k-1
        }
    }
}


// this method will not give the expedted output 
// because in the for loop we are changing the actual output 
// and when call stack will return to that iteration it will keep on changing 
// like if we have already added the output as "aaa" and we come to that stack
void printAllStr(vector<char> input, int k, int n, string output) {
    if(k == 0) {
        cout <<"|" << output << "|" << endl;
    }
    else {
        for(int i = 0; i < n; i++) {
            output = output + input[i];
            printAllStr(input, k-1, n, output);
        }
    }
}


int main() {
    vector<char> input{'a','b'};
    string output = "";
    generateStrings(input, 3, output);
    cout << endl << "================================" << endl;
    printAllStr(input, 3, 2, output);

    return 0;
}
