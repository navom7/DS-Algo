#include<iostream>
#include<vector>
#include<unordered_map>
#include <unordered_set>
#include<algorithm>
using namespace std;

int minSwaps(vector<int> arr){
	int n = arr.size();
	if(n < 2) return 0;
	pair<int,int> ap[n];
	for(int i = 0; i < n; i++) {
		ap[i].first = arr[i];
		ap[i].second = i;
	}
	sort(ap, ap+n);

	int ans = 0;

	vector<bool> visited(n, false);

	for(int i = 0; i < n; i++) {
		int old_position = ap[i].second;
		if(visited[i] || i == old_position) continue;

		int node = i;
		int cycle = 0;
		while(!visited[node]) {
			visited[node] = true;
			cycle++;
			node = ap[node].second;
		}
		ans += cycle;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> vec = {5,4,3, 9, 6,2,1};
	int res = minSwaps(vec);
	cout << res << endl;

	return 0;
}