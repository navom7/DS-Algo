#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int r, int mid) {
	
}

void mergeSort(int arr[], int l, int r) {
	int mid = l + (r-l)/2;
	mergeSort(arr, l, mid-1);
	mergeSort(arr, mid, r);
	merge(arr, l, r, mid);
}

int main() {
	int arr[8] = {4,-3,2,9,1,8,5,0};


	return 0;
}