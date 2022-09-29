class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mSort(nums, 0, n-1);
        return nums;
    }
    void mSort(vector<int> & arr, int s, int e){
        if(s >= e){
            return;
        }
        int m = s + (e-s)/2;
        mSort(arr, s, m);
        mSort(arr, m+1, e);
        Merge(arr, s, e);
        
    }
    void Merge(vector<int> & arr, int s, int e){
        int mid = s + (e-s)/2;
        int i = s;
        vector<int> temp;
        int j = mid+1;
        while(i <= mid && j <= e){
            if(arr[i] < arr[j]){
                temp.push_back(arr[i]);
                i++;
            } else {
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
        i = 0;
        for(int x = s; x <= e; x++){
            arr[x] = temp[i];
            i++;
        }
        return;
    }
};
