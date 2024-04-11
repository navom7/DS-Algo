// print all the subset of a string

#include<bits/stdc++.h>
using namespace std;

void printSubset(string str, int st, int end, string output){
    if(st >= end) {
        cout <<"\"" << output << "\"" << endl;
        return;
    }
    printSubset(str, st+1, end, output + str[st]);
    printSubset(str, st+1, end, output);
    return;
}

int main(){
    string str = "abc";
    string output = "";
    printSubset(str, 0, 3, output);
    cout << "printed Now" << endl;

    return 0;
}
