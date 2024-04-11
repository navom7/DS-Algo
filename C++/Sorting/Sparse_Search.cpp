//Find the index of a string in a list of string that contains empty strings also



#include <iostream>
#include<vector>
using namespace std;

int sparse_search(string arr[], int n, string f){
    int s = 0;
    int e = n-1;
    // for(int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    while(s <= e){
        int mid = s + (e-s)/2;
        int mid_Left = mid-1;
        int mid_right = mid+1;
        // cout << mid <<  " " << mid_Left << " " << mid_right << " " << arr[mid] << endl;
        while(1){
            if(mid_Left < s && mid_right > e){
                // cout << " haha1 ";
                return -1;
            } else if(mid_Left >= s && arr[mid_Left] != ""){
                mid = mid_Left;
                break;
            } else if(mid_right <= e && arr[mid_right] != ""){
                mid = mid_right;
                break;
            }
            mid_Left--;
            mid_right++;
        }
        if(arr[mid] == f){
            // cout << " haha2 ";
            return mid;
        } else if(arr[mid] > f){
            e = mid-1;
            // cout << " haha3 ";
        } else {
            // cout << " haha4 ";
            s = mid+1;
        }
        // cout << s << " " << e << " hai \n";
    }
    // cout << " haha5 ";
    return -1;
}

int main() {
    
    string arr[] = {"ai", "", "","bat", "","","car","cat","","","dog",""};
    int n = 12;

    string f;
    cin>>f;
    cout<<"Index of '" << f << "' in array is: " << sparse_search(arr,n,f)<<endl;

    
    return 0;
}
