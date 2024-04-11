#include<iostream>
#include<vector>
#include<unordered_map>
#include <unordered_set>
#include<algorithm>
using namespace std;

int minSwaps(vector<int> arr){
	int n = arr.size();
	if(n < 2) return 0;
	int cnt = 0;
	vector<int> temp = arr;
	sort(arr.begin(), arr.end());
	unordered_map<int,int> mp;
	unordered_set<int> visited;
	for(int i = 0; i < n; i++) {
		if(arr[i] != temp[i]){
			mp.insert({temp[i], arr[i]});
		}
	}
	for(auto x : mp) {
		visited.insert(x.first);
		int second = x.second;
		// cout << second << " ";
		int t = 20;
		while(t-- && visited.find(second) == visited.end()) {
			cnt++;
			// cout << second << " " << mp[second] << " - ";
			visited.insert(second);
			second = mp[second];
		}
		
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> vec = {5,4,3, 6,2,1};
	int res = minSwaps(vec);
	cout << res << endl;

	return 0;
}