//Difference of one element from each of both array find out minimum difference of any two element


#include <bits/stdc++.h>
using namespace std;

void min_pair(vector<int> a, vector<int> b){
    int p1, p2;
    int diff = INT_MAX;
    sort(b.begin(), b.end());
    for(auto x: a){
        int lb = lower_bound(b.begin(), b.end(), x) - b.begin();
        if(b[lb-1] == x){
            cout << b[lb-1] << " " << x << endl;
            return; 
        }
        if(lb >= 1 && (x - b[lb-1]) < diff){
            diff = b[lb-1]-x;
            p2 = x;
            p1 = b[lb-1];
        } else if(lb != b.size() && (b[lb]-x) < diff){
            diff = b[lb]-x;
            p1 = x;
            p2 = b[lb];
        }
    }
    cout << p1 << " " << p2 << endl;
}

int main() {
    vector<int> a1 = {-1, 5, 10, 20, 3};
	vector<int> a2 = {26, 134, 135, 15, 17};
	min_pair(a1,a2);


	return 0;
}
