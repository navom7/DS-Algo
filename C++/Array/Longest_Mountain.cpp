//845. Longest Mountain in Array
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int longest = 0;
        if(n == 0) return longest;
        for(int i = 1; i < n-1;) {
            int cnt = 1;
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
                int j = i;
                while(j > 0 && arr[j] > arr[j-1]) {
                    j--; cnt++;
                }
                while(i < n-1 && arr[i] > arr[i+1]) {
                    i++; cnt++;
                }
            } else {
                i++;
            }
            longest = max(longest, cnt);
        }
        return longest == 1 ? 0 : longest;
    }
    int max(int a, int b) {
        return a > b ? a : b;
    }
};