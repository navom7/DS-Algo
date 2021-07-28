#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Complete this method, don't write main
vector<string> fizzbuzz(int n){
    vector<string> res;
    for(int i = 1; i <= n; i++) {
        if(i%3 == 0) {
            res.push_back("Fizz");
        } else if(i % 5 == 0) {
            res.push_back("Buzz");
        } else if(i % 15 == 0) {
            res.push_back("FizzBuzz");
        } else {
            res.push_back(to_string(i));
        }
    }
    return res;
    
}

int main() {
	fizzbuzz(10);

}