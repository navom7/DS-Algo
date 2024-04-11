#include<iostream>
#include<vector>
using namespace std;

int highest_mountain(vector<int> arr) {
    int n = arr.size();
    if(n == 0) return n;
    int largest = 0;
    for(int i = 1; i < n-1; ) {
        int count = 1;
        int j = i;
        //check if a[i] is peak or not
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            while(j > 0 && arr[j] > arr[j-1]) {
                count++; j--;
            }
            while(i < n-1 && arr[i] > arr[i+1]) {
                i++; count++;
            }
        } else {
            i++;
        }
        largest = max(largest, count);
    }
    return largest;
}


int main() {
    vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    int largest = highest_mountain(arr);
    cout << "Largest Mountain: " << largest;

    return 0;
}