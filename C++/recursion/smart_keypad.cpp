// print all the possible output strings from a 0 to  9 keypad phone


#include<iostream>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void print_keypad_output(string input, string output, int i = 0) {
    if(input[i] == '\0'){
        cout << output << endl;
        return;
    }
    int curr_digit = input[i] - '0';
    if(curr_digit < 2) {
        print_keypad_output(input, output, i+1);
    }
    for(int k = 0; k < keypad[curr_digit].size(); k++) {
        print_keypad_output(input, output+keypad[curr_digit][k], i+1);
    }
    return;
}


int main() {
    string input; cin >> input;
    string output = "";
    print_keypad_output(input, output, 0);


    return 0;
}

