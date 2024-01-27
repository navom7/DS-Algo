#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges)
{

    if(sequence.size() < n) {
        return false;
    }
    if(n < 2) {
        return false;
    }

    vector<bool> visited(n+1, false);
    vector<vector<int>> lst(n+1);
    vector<int> level(n+1, 0);

    for(auto x: edges) {
        lst[x[0]].push_back(x[1]);
        lst[x[1]].push_back(x[0]);
    }



    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int frnt = q.front();
        q.pop();

        for(auto x: lst[frnt]) {
            if(!visited[x]) {
                q.push(x);
                level[x] = level[frnt]+1;
                visited[x] = true;
            }
        }
    }

    for(int i = 1; i < n; i++) {
        int curr = level[sequence[i]];
        int prev = level[sequence[i-1]];

        if(curr < prev)
            return false;
    }

    return true;
}


int main() {
    vector<vector<int>> edges = 
    {
        {1,2}, {1,3}, {1,4},
        {2,6}, {3,5}, {3, 9}, {6, 8}, {6,7},
        {5, 12}, {5, 11}, {5, 10}
    };

    vector<int> sequence = {1,2,3, 10,4,6,5, 9, 8, 7, 12, 11};

    int n = 12;

    if(validBfs(n, sequence, edges)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    

}