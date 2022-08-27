#include <iostream>
#include<vector>
using namespace std;

vector<vector<int> > triplets(vector<int> vec, int targetSum){
    int n = vec.size();
    vector<vector<int> > result;
    if(n <= 2)
        return result;
    for(int i = 0; i < n; i++) {
        int j = i+1;
        int k = n-1;
        
        while(j < k) {
            int sum = vec[i];
            sum += vec[j];
            sum += vec[k];
            if(sum == targetSum){
                result.push_back({vec[i], vec[j], vec[k]});
                j++; k--;
            } else if(sum > targetSum){
                k--;
            } else 
                j++;
        }
    }
    return result;
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
