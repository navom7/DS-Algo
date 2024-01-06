#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int boxStacking(vector<vector<int>> &boxes, int R, int C) {
    
}

int main() {

    vector<vector<int>> boxes = {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5}
    }

    int height = boxStacking(boxes, boxes.size(), boxes[0].size());
    return 0;
}