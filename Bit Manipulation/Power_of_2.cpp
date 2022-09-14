#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    if((n&(n-1)) == 0){
        cout << "yes it is a power of 2";
    } else {
         cout << "no it is not a power of 2";
    }
}
