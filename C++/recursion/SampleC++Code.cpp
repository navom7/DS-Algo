#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vec = {1,3,4,5,5};
    for(auto x: vec) {
        cout << n*4 << " " << x << endl;
    }

    return 0;
}
