// Cost of merging two ropes is sum of length of two merging ropes

// Input
// n = 4
// Ropes[] = {4,3,2.6}

// Output
// 29

#include<iostream>
#include<queue>

using namespace std;


void MergingRopes(vector<int> ropes, int n) {
    priority_queue<int, vector<int>, greater<int>> q(ropes.begin(), ropes.end());
    int cost = 0;
    while(q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        cost += (a+b);
        q.push(a+b);
    }

    cout << cost;

}



int main() {
    
    vector<int> input = {4,3,2,6};
    MergingRopes(input, input.size());

    return 0;
}