#include<iostream>
#include<vector>
using namespace std;

pair<char,int> gow(string s, int i, int j, int n, vector<vector<pair<char,int>>> &dp, char turn) {
    if (i >= n || j < 0 || i > j) {
        return {'.', 0};
    }
    if (dp[i][j].first != '.') {
        return dp[i][j];
    }

    pair<char, int> result;
    if (turn == 'O') {
        if (s[i] == s[j] && s[i] == 'H') {
            return dp[i][j] = {'H', j - i + 2};
        } else if (s[j] == 'H') {
            return dp[i][j] = gow(s, i + 1, j, n, dp, 'H');
        } else if (s[i] == 'H') {
            return dp[i][j] = gow(s, i, j - 1, n, dp, 'H');
        } else {
            pair<char, int> a = gow(s, i, j - 1, n, dp, 'H');
            pair<char, int> b = gow(s, i + 1, j, n, dp, 'H');
            if (a.second > b.second) {
                return dp[i][j] = a;
            } else {
                return dp[i][j] = b;
            }
        }
    } else {
        if (s[i] == s[j] && s[i] == 'O') {
            return dp[i][j] = {'O', j - i + 2};
        } else if (s[j] == 'O') {
            return dp[i][j] = gow(s, i + 1, j, n, dp, 'O');
        } else if (s[i] == 'O') {
            return dp[i][j] = gow(s, i, j - 1, n, dp, 'O');
        } else {
            pair<char, int> a = gow(s, i, j - 1, n, dp, 'O');
            pair<char, int> b = gow(s, i + 1, j, n, dp, 'O');
            if (a.second > b.second) {
                return dp[i][j] = a;
            } else {
                return dp[i][j] = b;
            }
        }
    }
}

pair<char,int> GameOfWits(string s){
    int n = s.size();
    cout << s << endl;
    vector<vector<pair<char,int>>> dp(n, vector<pair<char,int>>(n, {'.', 0}));

    auto result = gow(s, 0, n-1, n, dp, 'O');
    

    
    
    return result;
    
}

int main() {
    string input_string = "HOOOOHHOHOOOOHHOHOOOOHHOHOOOOHHOHOOOOHHOHOOOOHHOHOOOOHHOHOOOOHHOHOOOOHHOHOOOOHHOHOOOOHHOHOOOOHHOHOOOOHHOHOOOOHHOHOOOOHHO";
    pair<char, int> result = GameOfWits(input_string);

    cout << result.first << " " << result.second << endl;

    return 0;
}