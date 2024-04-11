// Find if any subset is there with sum equals to the given sum

#include<bits/stdc++.h>
using namespace std;

bool subsetSumToX(vector<int> &vec, int sum, int start) {
    if(start >= vec.size() && sum != 0) {
        return false;
    }
    if(sum == 0) {
        return true;
    }
    if(sum < 0) {
        return false;
    }
    bool a = subsetSumToX(vec, sum-vec[start], start+1);
    bool b = subsetSumToX(vec, sum, start+1);
    return a || b;
}

int main() {
    vector<int> vec{10,12,15,7,19,20};
    int sum = 16;
    cout << subsetSumToX(vec, sum, 0) << endl;
}
