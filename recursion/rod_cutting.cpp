/* 

Given a list of prices for every length
and length of the rod

find out the maximum amount that can be made by breaking that rod into smaller length

prices = [1, 5, 8, 9, 10, 17, 17, 20]
Rod Length = 8

output 17 + 5 = 22
a length 2 and 6


*/


#include<bits/stdc++.h>
using namespace std;

int cutting_rod(vector<int> &vec, int len){
    cout << len << " ";
    if(len <= 0){
        return 0;
    }
    int price = INT_MIN;
    for(int i = 0; i < len; i++){
        int temp_price = vec[i] + cutting_rod(vec, len-i-1);
        price = max(price, temp_price);
    }
    return price;
}

int main(){
    int len;
    vector<int> vec = {1, 5, 8, 9, 10, 17, 17, 20};
    len = vec.size();
    cout << "output: " << cutting_rod(vec, len) << endl;


    return 0;
}
