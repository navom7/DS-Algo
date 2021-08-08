#include<iostream>
#include<vector>
using namespace std;

int rainTrap(vector<int> arr) {
	int n = arr.size();
	if(n <= 2) return 0;
	int leftMax[n] = {arr[0]};
	int rightMax[n] = {0};
	rightMax[n-1] = arr[n-1];
	int trapAmount = 0;
	for(int i = 1; i < n-1; i++) {
		leftMax[i] = max(arr[i], leftMax[i-1]);
		rightMax[n-i-1] = max(arr[n-i-1], rightMax[n-i]);
	}
	for(int i = 1; i < n-1; i++) {
		trapAmount += (min(leftMax[i], rightMax[i]) - arr[i]);
	}
	return trapAmount;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> arr{1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << rainTrap(arr) << endl;

	return 0;
}