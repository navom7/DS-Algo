#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges)
{
    vector<vector<int>> lst(n+1);
    



    for(auto x: lst) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << endl;
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

    vector<int> sequence = {1,2,3,4,6,5, 9, 8, 7, 12, 11, 10};

    int n = 12;

    if(validBfs(n, sequence, edges)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    

}