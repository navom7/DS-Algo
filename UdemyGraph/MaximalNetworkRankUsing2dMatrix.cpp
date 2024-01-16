#include<iostream>
#include<vector>

using namespace std;


int maximalNetworkRank(int n, vector<vector<int>> roads) {

    vector<vector<int>> adjacencyMatrix(n, vector<int> (n, 0));
    vector<int> networkRank(n, 0);

    for(auto x: roads) {
        int i = x[0];
        int j = x[1];

        networkRank[i]++;
        networkRank[j]++;

        adjacencyMatrix[i][j] = 1;
        adjacencyMatrix[j][i] = 1;
    }

    int maximumRank = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int newRank = networkRank[i] + networkRank[j];
            if(adjacencyMatrix[i][j] == 1) {
                newRank -= 1;
            }
            if(newRank > maximumRank) 
                maximumRank = newRank;
        }
    }
    return maximumRank;

}

int main() {
    int n = 4;
    vector<vector<int>> roads = {
        {0,1}, {0,3}, {1,2}, {1,3}
    };
    cout << maximalNetworkRank(n, roads) << endl;
}