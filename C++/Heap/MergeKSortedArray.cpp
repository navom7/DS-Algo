// Cost of merging two ropes is sum of length of two merging ropes

// Merge K-Sorted Arrays
// As discussed, you need to implement a function that accepts k-sorted arrays of integers and returns the sorted version of the array.
// (Solve it using heaps only, other sorting algorithms are not allowed for this problem) You may use the inbuilt heap data structure.

// Sample Input
// Input is 2D Vector, each row represents a sorted array. There are K such rows.
// {{10,15,20,30},
// {2,5,8,14,24},
// {0,11,60,90}}

// Sample Output
// { 0 2 5 8 10 11 14 15 20 24 30 60 90 }

#include<iostream>
#include<queue>

using namespace std;


vector<int> mergeKArrays(vector<vector<int>> arrs) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> res;
    for(auto m : arrs) {
        for(auto n: m) {
            cout << n << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < arrs.size(); i++) {
        vector<int> vec;
        vec.push_back(arrs[i][0]);
        vec.push_back(i);
        vec.push_back(0);
        pq.push(vec);
    }
    
    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        int num = x[0];
        int row_idx = x[1];
        int col_idx = x[2];
        res.push_back(num);
        if(col_idx < arrs[row_idx].size()-1) {
            int new_num = arrs[row_idx][col_idx+1];
            vector<int> newvec;
            newvec.push_back(new_num);
            newvec.push_back(row_idx);
            newvec.push_back(col_idx+1);
            pq.push(newvec);
        }
    }
    
    return res;
}



int main() {
    
    vector<vector<int>> arr = {{10,15,20,30},
                            {2,5,8,14,24},
                            {0,11,60,90}};
    vector<int> result = mergeKArrays(arr);

    for(auto x: result) {
        cout << x << " ";
    }
    return 0;
}