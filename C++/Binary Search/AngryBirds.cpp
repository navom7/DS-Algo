//Find the maximum for minimum distance between two birds




#include <bits/stdc++.h>
using namespace std;

float AngryBirds(int n, vector<int> nest, int brd){
    if(n <= 1){
        return 0;
    }
    int s = 1;
    int e = nest[n-1];
    int ans = -1;
    while(s <= e) {
        int mid = s + (e-s)/2;
        int lastPzn = nest[0];
        int cnt = 1;
        // cout << s << " " << mid << " " << e << endl;
        for(int i = 1; i < n; i++){
            
            if((nest[i] - lastPzn) >= mid){
                cnt++;
                lastPzn = nest[i];
            } 
            cout << lastPzn << " ";
        }
        cout << endl << endl;
        cout << "Cnt: " << cnt << "  mid: " << mid << endl;
        if(cnt >= brd){
            ans = max(ans, mid);
            s = mid+1;
        } else {
            e = mid-1;
        }
        cout << endl;
        
    }
    return ans;
    
}


int main() {
    int n; cin >> n;
    vector<int> nests{1,2,4,8,9};
    
    int birds; cin >> birds;
    cout << AngryBirds(n, nests, birds) << endl;
    
    return 0;
}
