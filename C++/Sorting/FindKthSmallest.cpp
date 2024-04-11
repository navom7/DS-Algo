//To Find kth Smallest Element from unsorted array



#include <iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int s, int e){
    int pv = arr[e];
    int i = s-1;
    
    for(int j = s; j <= e; j++){
        if(arr[j] < pv){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[e]);
    return i;
    
}

int QuickSort(vector<int> &arr, int s, int e, int k){
    cout << s << " " << e << endl;
    
    if(s > e)
        return -1;
    
    int p = partition(arr, s, e);
    if(p == k){
        return arr[p];
    }
    if(p > k)
        return QuickSort(arr, s, p-1, k);
    else
        return QuickSort(arr, p+1, e, k);
}

int main() {
    vector<int> arr{10,5,-2,0,7,6,4};
    // cout<< arr.size() <<endl;
    int n = arr.size();

    cout << QuickSort(arr,0,n-1, 0) << endl;

    for(int x :arr){
    	cout << x << " ";
    }

    
    return 0;
}
