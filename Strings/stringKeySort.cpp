/*
Sample Input
------------
3
92 022
82 12
77 13
2 false numeric
Sample Output
-------------
82 12
77 13
92 022
*/


#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


string findKey(string str, int key){
    // char *inputstr = ;
    // cout << inputstr << endl;
    
    char *inputstr = strtok((char *) str.c_str(), " ");
    
    while(key > 1){
        inputstr = strtok(NULL, " ");
        key--;
    }
    cout << "key => " << inputstr << endl;
    // return "23";
    return (string)inputstr;
}


int convertToInt(string str){
    int res = 0;
    int p = 1;
    for(int i = str.length()-1; i >= 0; i--){
        int dig = str[i] - '0';
        res = res*p + dig;
        p = p*10;
    }
    return res;
}

bool numComparer(pair<string, string> p1, pair<string, string> p2){
    int key1 = convertToInt(p1.first);
    int key2 = convertToInt(p2.first);
    return key1 < key2;
}

bool stringComparer(pair<string, string> p1, pair<string, string> p2){
    return p1.first < p2.first;
}



int main() {
    vector<string> input;
    int n; cin >> n;
    
    string temp;
    
    cin.get(); //consumes the extra \n
    cout << "Input: " << endl;
    for(int i = 0; i< n; i++){
        getline(cin, temp);
        input.push_back(temp);
    }
    for(auto x : input){
        cout << x << endl;
    }
    cout << endl << "Keys to compare: " << endl;
    int key;
    string reverse, sorting;
    cin >> key >> reverse >> sorting;
    
    vector<pair<string,string> > kvstr;
    for(int i = 0; i < n; i++){
        kvstr.push_back({findKey(input[i], key), input[i]});
    }
    if(sorting == "numeric") 
        sort(kvstr.begin(), kvstr.end(), numComparer);
    else
        sort(kvstr.begin(), kvstr.end(), stringComparer);
    cout << endl;
    // if(reverse == "true"){
    //     reverse(kvstr.begin(),kvstr.end());
    // }
    cout << "Output: " << endl;
    for(auto x : kvstr){
        cout << x.second << endl;
    }
    
    
    return 0;
}
