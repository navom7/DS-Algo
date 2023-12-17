// Running Median

#include<iostream>
#include<queue>

using namespace std;


void RunningMedian(vector<int> arr, int n) {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    max_heap.push(arr[0]);

    for(int i = 1; i < n; i++) {
        int a = min_heap.size();
        int b = max_heap.size();
        int x = arr[i];
        if(a == b) {
            cout << "a -> " << i << " " << (double)((double)max_heap.top()+(double)min_heap.top())/2.0 << endl;
            if(arr[i] <= max_heap.top()) {
                max_heap.push(arr[i]);
            } else {
                min_heap.push(arr[i]);
            }
        } else if(a <= b) {
            cout << "b -> " << i << " " <<max_heap.top() << endl;
            if(x < max_heap.top()) {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(x);
            } else {
                min_heap.push(arr[i]);
            }
        } else {
            cout << "c -> " << i << " " <<min_heap.top() << endl;
            if(x >= min_heap.top()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(x);
            } else 
                max_heap.push(arr[i]);
        }
    }
    int a = min_heap.size();
        int b = max_heap.size();
    if(a == b) {
            cout << "a -> " << n << " " << (double)((double)max_heap.top()+(double)min_heap.top())/2.0 << endl;
        } else if(a < b) {
            cout << "b -> " << n << " " <<max_heap.top() << endl;
        } else {
            cout << "c -> " << n << " " <<min_heap.top() << endl;
        }

}



int main() {
    
    vector<int> input = {10,5,2,3,0,12,18,20,22};
    RunningMedian(input, input.size());

    return 0;
}