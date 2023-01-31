// There is a ladder of n steps, you can take atmost k steps at once (from 1 to k steps).
// Find out in how many ways you can reach to the top

#include<iostream>
using namespace std;

int n_ladder_top_down(int n, int k){
    if(n < 0)
        return 0;
    if(n == 0 || n == 1)
        return 1;
    int sum = 0;
    for(int i = 1; i <= k; i++){
        sum += n_ladder_top_down(n-i, k);
    }
    return sum;
}


// int n_ladder_bottom_up(int n, int k){
//     if()
// }


int main(){
    int n, k; cin >> n >> k;
    cout <<"N Ladder ===========================> " << n_ladder_top_down(n, k) << endl;


    return 0;
}