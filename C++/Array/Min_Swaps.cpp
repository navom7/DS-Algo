#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>


using namespace std;

int countMinSwaps(vector<int> arr){
    int n = arr.size();
    if(n < 2)
        return 0;
    vector<pair<int,int> > pv;
    for(int i = 0; i < n; i++){
        pv.push_back(make_pair(arr[i], i));
    }
    sort(pv.begin(), pv.end());
    int cycle = 0;
    vector<int> visited(n, 0);
    
    for(int i = 0; i < n; i++){
        if(visited[i] || i == pv[i].second)
            continue;
        int node = i;
        int cnt = 0;
        while(visited[node] == false){
            cnt++;
            visited[node] = true;
            node = pv[node].second;
        }
        cycle += cnt-1;
    }
    return cycle;
}



int main(){
    
    vector<int> arr{10,11,5,4,3,2,1};
    cout<<countMinSwaps(arr)<<endl;
    
    return 0;
}
