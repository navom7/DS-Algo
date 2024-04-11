#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<vector<int>> triplets(vector<int> arr, int S){
	vector<vector<int>> res ;
	int n = arr.size();
	if(n == 0) return res;
	for(int i = 0; i < n; i++) {
		int targetSum = S-arr[i];
		int j = i+1;
		int k = n-1;
		while(j < k) {
			int sum = arr[j]+arr[k];
			if(sum == targetSum) {
				vector<int> tempVec;
				tempVec.push_back(arr[i]);
				tempVec.push_back(arr[j]);
				tempVec.push_back(arr[k]);
				res.push_back(tempVec);
				j++;k--;
			} else if(sum < targetSum) { j++; }
			else { k--;	}
		}
	}
	return res;
}

int main() {
	vector<int> arr{1,2,3,4,5,6,7,8,9, 15};
	int S = 18;
	
	auto result = triplets(arr, S);
	for(auto x : result) {
		for(auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
}
