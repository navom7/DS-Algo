#include <iostream>

using namespace std;

int main() {
    string par = "We are learning about STL strings. STL string class is quite powerful";
    
    string word;
    getline(cin, word);
    
    cout << par.find(word) << endl; //if not found prints INT_MAX value
    
    int idx = par.find(word); 
    cout << idx << endl; // converts unsigned long int to signed int
    
    
    //if we need to start searching after any index
    idx = par.find(word, idx+1);
    cout << idx << endl;
    
    
    return 0;
}
