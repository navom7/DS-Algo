#include<iostream>
#include<vector>

using namespace std;



int main() {

    int wts[] = {2, 7, 3, 4};
    int prices[] = {5, 20, 20, 10};
    int N = 4;
    int W = 11;

    cout << knapsack(wts, prices, N, W) << endl;

    return 0;
}