#include<iostream>
#include<vector>

using namespace std;

vector<int> findPrimeNumbers(int n) {
    vector<int> res;
    vector<bool> isPrime(n+1, true);

    isPrime[0] = isPrime[1] = false;

    for(int p = 2; p <= n; p++) {
        if(isPrime[p] == true) {
            for(int i = p*p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for(int i = 0; i <= n; i++) {
        if(isPrime[i] == true) {
            res.push_back(i);
        }
    }
    return res;
}

int binarySearchHelper(int st, int end, vector<int> &primes, int num) {
    
    for(int i = end; i >= st; i++) {
        if(num%i)
    }
}

int binarySearch(vector<int> &arr, int n) {
    int end = n/2 + 1;

}


int main() {
    int n = 100;
    vector<int> res = findPrimeNumbers(n);

    for(auto x: res) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> arr = {10, 22, 28, 50};
    vector<int> cost = {4,5,6,7};





    return 0;
}