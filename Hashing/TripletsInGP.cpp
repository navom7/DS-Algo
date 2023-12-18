// find number of all the triplets in an array at indexes i, j and k 
// where i < j < k 
// and arr[i], arr[j], arr[k] are in GP

// Sample Input 
// 6
// 1 16 4 16 64 16
// 4

// Output:
// 3


#include<iostream>
#include<unordered_map>

using namespace std;

void FindTriplets(vector<int> input, int n, int r) {
    unordered_map<long, long> left, right;
    long count = 0;
    for(auto x: input) {
        right[x]++;
    }

    for(auto x: input) {
        right[x]--;
        count += (left[x/r] * right[x*r]);
        left[x]++;
        cout << "count: " << count << endl;
    }
    cout << count << endl;
}

int main() {
    int n,r; cin >> n;
    vector<int> inputArray;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        inputArray.push_back(k);
    }
    cin >> r;

    FindTriplets(inputArray, n, r);

    return 0;
}