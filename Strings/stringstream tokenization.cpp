#include <iostream>
#include<sstream>
#include<vector>
using namespace std;


int main() {
    string input;
    getline(cin, input);
    
    string token;
    vector<string> tokens;
    stringstream ss(input);
    
    while(getline(ss, token, ' ')){
        tokens.push_back(token);
    }
    for(auto x : tokens){
        cout << x << "\n";
    }
    
    return 0;
}
