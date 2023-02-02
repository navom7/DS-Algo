// given an amount (i.e 15)
// and a list of coins i.e {1, 3, 7, 10}
// Find out minimum number of coins needed to make that amount

#include<bits/stdc++.h>
using namespace std;

int coin_change(vector<int> &coins, int amount){
    if(amount <= 0){
        return 0;
    }
    int mn = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        if(amount >= coins[i])
            mn = min(mn, coin_change(coins, amount-coins[i]));
    }
    return mn+1;
}


int main(){
    int amount;
    cout << "Enter amount: ";
    cin >> amount;
    cout << endl << "Enter the number of types of coins: ";
    int n; cin >> n;
    vector<int> coins;
    while(n--){
        int temp;
        cout << endl << "enter next Number: ";
        cin >> temp;
        coins.push_back(temp);
    }
    cout << "minimum number of coins needed: " << coin_change(coins, amount) << "\n\n\n\n\n";
    return 0;
}