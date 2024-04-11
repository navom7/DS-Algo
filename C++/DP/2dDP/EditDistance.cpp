// Edit Distance
// Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’. 
// Insert
// Remove
// Replace
// All of the above operations are of equal cost.
// Input Format
// Function contains two strings str1 and str2 as parameters.
// Output Format
// Return a single integer representing minimum number of operations required to convert str1 to str2
// Constraints
// 1 <= str1.length() <= 100
// 1 <= str2.length() <= 100
// Sample Testcases:
// Input:   str1 = "geek", str2 = "gesek"
// Output:  1
// We can convert str1 into str2 by inserting a 's'.

// Input:   str1 = "cat", str2 = "cut"
// Output:  1
// We can convert str1 into str2 by replacing 'a' with 'u'.

// Input:   str1 = "sunday", str2 = "saturday"
// Output:  3
// Last three and first characters are same.  We basically
// need to convert "un" to "atur".  This can be done using
// below three operations.
// Replace 'n' with 'r', insert t, insert a




#include<iostream>
#include<vector>
using namespace std;
int editDistanceRecursive(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    int m = s1.size();
    int n = s2.size();
    if(i >= m) {
        return dp[i][j] = n-j;
    }
    if(j >= n) {
        return dp[i][j] = m-i;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int a = 0, b = 0, c = 0;
    if(s1[i] == s2[j]) {
        return dp[i][j] = editDistanceRecursive(s1, s2, i+1, j+1, dp);
    } else {
        a = 1 + editDistanceRecursive(s1, s2, i+1, j, dp);
        b = 1 + editDistanceRecursive(s1, s2, i, j+1, dp);
        c = 1 + editDistanceRecursive(s1, s2, i+1, j+1, dp);
        return dp[i][j] = min(a, min(c, b));
    }
}

int editDistance(string str1, string str2){
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    return editDistanceRecursive(str1, str2, 0, 0, dp);
}
int main() {
    string s1 = "sunday";
    string s2 = "saturday";
        cout << editDistance(s1, s2) << endl;
        return 0;
}