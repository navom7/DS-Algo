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

void QuickSort(vector<int> &arr, int s, int e){
    if(s >= e)
        return;
    
    int p = partition(arr, s, e);
    QuickSort(arr, s, p-1);
    QuickSort(arr, p+1, e);
    
    return;
}

int main() {
    vector<int> arr{10,5,-2,0,7,6,4};
    cout<< arr.size() <<endl;
    int n = arr.size();

    QuickSort(arr,0,n-1);

    for(int x :arr){
    	cout << x << " ";
    }

    
    return 0;
}
