#include<bits/stdc++.h>
using namespace std;

int min(int x, int y) { return (x<y)? x :y; }

void merge(vector<int> &arr, int l, int mid, int r) {
	if(l >= r) return;
	int temp[r-l+1] = {0};
	int i = l, j = mid+1, k = 0;
	while(i <= mid && j <= r) {
		if(arr[i] < arr[j]) {
			temp[k] = arr[i];
			k++;i++;
		} else {
			temp[k] = arr[j];
			k++;j++;
		}
	}
	while(i <= mid) {
		temp[k] = arr[i];
		i++;k++;
	}
	while(j <= r) {
		temp[k] = arr[j];
		j++;k++;
	}
	for(int i = 0; i <= r-l; i++) {
		arr[i+l] = temp[i];
	}

}

void mergeSort(vector<int> &arr, int r) {
	int curr_size;
	int left_st;
	for(curr_size = 1; curr_size < r; curr_size = 2*curr_size) {
		
		for(left_st = 0; left_st < r-1; left_st += 2*curr_size) {
			
			int mid = min(curr_size+left_st-1, r-1);
			int right_end = min(left_st+2*curr_size - 1, r-1);
			
			merge(arr, left_st, mid, right_end);
		}
	}
}

int main() {
	 vector<int> arr = {4,-3,2,9,1,8,5,0};
	 int n = 8;
	 mergeSort(arr, 8);
	 for(auto x : arr) {
	 	cout << x << " ";
	 }
	 
	return 0;
}
