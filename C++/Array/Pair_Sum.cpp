#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<int> pairSum(vector<int> arr, int S) {
	unordered_set<int> st;
	vector<int> res;
	for(auto x : arr) {
		if(st.find(S-x) != st.end()) {
			res.push_back(x); res.push_back(S-x);
		}
		st.insert(x);
	}
	return res;
}

int main() {
	vector<int> arr{10, 5, 2, 3, -6, 9, 11};
	int S = 4;
	
	auto p = pairSum(arr, S);
	if(p.size() == 0) {
		cout << "No Such pair exist!" << endl;
	} else {
		cout << p[0] << ", " << p[1] << endl;
	}
	
	return 0;
}
