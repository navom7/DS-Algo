#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];    
}

int boxStacking(vector<vector<int>> &boxes, int R, int C) {
    sort(boxes.begin(), boxes.end(), compare);
    // for(auto x: boxes) {
    //     cout << x[0] << " " << x[1] << " " << x[2] << endl;
    // }

    vector<int> dp(R, 0);
    dp[0] = boxes[0][2];

    int ans = 0;

    for(int i = 1; i < R; i++) {
        int cl = boxes[i][0];
        int cb = boxes[i][1];
        int ch = boxes[i][2];

        for(int k = 0; k < i; k++) {
            int l = boxes[k][0];
            int b = boxes[k][1];
            int h = boxes[k][2];

            if(l < cl && b < cb) {
                cout << l << " " << b << " " << h << endl;
                cout << cl << " " << cb << " " << ch << endl;
                cout << i << " " << k << endl;
                cout << dp[i] << endl;
                dp[i] = max(dp[i], dp[k] + ch);
                cout << dp[i] << endl << endl;
            }
        }

        if(dp[i] == 0) {
            dp[i] = ch;
        }
        ans = max(dp[i], ans);
    }

    for(auto x: dp) {
        cout << x << " ";
    }
    cout << endl;

    return ans;

}

int main() {

    vector<vector<int>> boxes = {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5}
    };

    int height = boxStacking(boxes, boxes.size(), boxes[0].size());
    
    cout << height << endl;
    return 0;
}