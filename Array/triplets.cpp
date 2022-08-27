#include <iostream>
#include<vector>
using namespace std;

vector<vector<int> > triplets(vector<int> vec, int targetSumb){
    
}

int main() {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int targetSum = 18;
    vector<vector<int> > result = triplets(vec, targetSum);
    for(auto v : result){
        for(auto n : v){
            cout << n << " ";
        }
        cout << endl;
    }
}
