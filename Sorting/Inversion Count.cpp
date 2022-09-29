//Inversion Count: Count number of pairs a[i], a[j]
//  such that a[i] > a[j] and i < j



#include <bits/stdc++.h>
using namespace std;


int merge(vector<int> & arr, int s, int e){
    int mid = s + (e-s)/2;
    int cnt = 0;
    int i = s;
    int j = mid+1;
    vector<int> temp;
    while(i <= mid && j <= e){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else {
            cnt += (mid-i+1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= e){
        temp.push_back(arr[j]);
        j++;
    }
    j = 0;
    for(i = s; i <= e; i++){
        arr[i] = temp[j++];
    }
    return cnt;
}

int inveCount(vector<int> &arr, int s, int e){
    if(s >= e){
        return 0;
    }
    int mid = s + (e-s)/2;
    int a = inveCount(arr, s, mid);
    int b = inveCount(arr, mid+1, e);
    int c = merge(arr, s, e);
    return a+b+c;
}

int main() {
    vector<int> vec{0,5,2,3,1};
    int s = 0;
    int e = vec.size()-1;
    cout << inveCount(vec, s, e) << endl;
    
    
    return 0;
}
