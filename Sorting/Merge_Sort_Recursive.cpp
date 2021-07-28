#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int r, int mid) {
	if(l > r) return;
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
	for(int i = 0; i < r-l+1; i++) {
		arr[i+l] = temp[i];
	}

}

void mergeSort(int arr[], int l, int r) {
	if(l >= r) return;
	int mid = l + (r-l)/2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid+1, r);
	merge(arr, l, r, mid);
}

int main() {
	int arr[8] = {4,-3,2,9,1,8,5,0};
	int n = 8;
	mergeSort(arr, 0, 7);
	for(auto x : arr) {
		cout << x << " ";
	}

	return 0;
}