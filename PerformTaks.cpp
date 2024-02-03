#include<iostream>
#include<vector>
#include<cstring>
#include<sstream>

using namespace std;

void performTask(vector<int> &balance, vector<string> &request) {
    int n = balance.size();
    vector<vector<string>> instructions;
    for(auto x: request) {
        stringstream ss(x);

        string token;
        vector<string> tokens;
        while(getline(ss, token, ' ')) {
            tokens.push_back(token);
        }
        instructions.push_back(tokens);
    }

    for(auto x: instructions) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }

    for(auto ins: instructions) {
        if(ins[0] == "withdraw") {
            int ids = stoi(ins[1]);
            int amount = stoi(ins[2]);
            balance[ids-1] -= amount;

        } else if(ins[0] == "transfer") {
            int frm = stoi(ins[1]);
            int to = stoi(ins[2]);
            int amount = stoi(ins[3]);

            balance[frm-1] -= amount;
            balance[to-1] += amount;
        } else if(ins[0] == "deposit") {
            int ids = stoi(ins[1]);
            int amount = stoi(ins[2]);


            balance[ids-1] += amount;

        } else {
            continue;
        }
    }

}

int main() {
    vector<int> balance = {10,100,20,50,30};
    vector<string> request = {"withdraw 2 10", "transfer 5 1 20",  "deposit 5 20",  "transfer 3 4 15"};


    performTask(balance, request);

    cout << endl;
    for(auto x: balance) {
        cout << x <<  " ";
    }
    cout << endl;

    return 0;
}