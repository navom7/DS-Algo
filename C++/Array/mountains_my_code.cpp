#include <iostream>
#include<vector>
using namespace std;

int maxWidthOfMaountain(vector<int> arr){
    int n = arr.size();
    if(n < 3)
        return 0;
    int mw = 0, cw = 1, si = 0, i = 1;
    if(arr[0] < arr[1]){
        si = 1;
    }
    while(i < n) {
        while(i < n && arr[i] > arr[i-1]){
            cw++;i++;
        }
        while(i < n && arr[i] < arr[i-1]){
            cw++; i++;
        }
        if(cw > mw)
            mw = cw;
        cw = 1;
    }
    return mw;
}

int main() {
    vector<int> vec{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    int targetSum = 18;
    int result = maxWidthOfMaountain(vec);
    cout << "Maximum length of mountain: " << result << endl;
}
